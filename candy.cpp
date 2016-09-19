// CannyStill.cpp

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv/cv.h>

#include<iostream>
#include <chrono>
#include <time.h>
#include <thread>
#include<conio.h>           // may have to modify this line if not using Windows
using namespace std;
using namespace cv;

///////////////////////////////////////////////////////////////////////////////////////////////////
//int main() {
//
//
//
//
//	//cv::Mat imgOriginal;        // input image
//	//cv::Mat imgGrayscale;       // grayscale of input image
//	//cv::Mat imgBlurred;         // intermediate blured image
//	//cv::Mat imgCanny;           // Canny edge image
//
//
//	//imgOriginal = cv::imread("image.jpg");          // open image
//
//	//if (imgOriginal.empty()) {                                  // if unable to open image
//	//	std::cout << "error: image not read from file\n\n";     // show error message on command line
//	//	_getch();                                               // may have to modify this line if not using Windows
//	//	return(0);                                              // and exit program
//	//}
//
//	//cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);       // convert to grayscale
//
//	//cv::GaussianBlur(imgGrayscale,          // input image
//	//	imgBlurred,                         // output image
//	//	cv::Size(5, 5),                     // smoothing window width and height in pixels
//	//	1.5);                               // sigma value, determines how much the image will be blurred
//
//	//cv::Canny(imgBlurred,           // input image
//	//	imgCanny,                   // output image
//	//	100,                        // low threshold
//	//	200);                       // high threshold
//
//	//								// declare windows
//	//cv::namedWindow("imgOriginal", CV_WINDOW_AUTOSIZE);     // note: you can use CV_WINDOW_NORMAL which allows resizing the window
//	//cv::namedWindow("imgCanny", CV_WINDOW_AUTOSIZE);        // or CV_WINDOW_AUTOSIZE for a fixed size window matching the resolution of the image
//	//														// CV_WINDOW_AUTOSIZE is the default
//	//cv::imshow("imgOriginal", imgOriginal);     // show windows
//	//cv::imshow("imgCanny", imgCanny);
//
//	//cvNamedWindow("Camera_Output", 1);
//	//CV_CAP_ANY
//	//CvCapture* capture = cvCaptureFromCAM(CV_CAP_ANY);
//	VideoCapture capture(0);
//	
//	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
//	capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
//	capture.set(CV_CAP_PROP_FPS, 30);
//	double fps = capture.get(CV_CAP_PROP_FPS);
//	//capture.set(CV_CAP_PROP_FOURCC, CV_FOURCC('B', 'G', 'R', '3'));
//	//cv::waitKey(0);
//
//	//IplImage frame1 = cvQueryFrame(capture); //Create image frames from capture
//	//IplImage frame2 = cvQueryFrame(capture);
//	//IplImage frame3 = cvQueryFrame(capture);
//	//
//	Mat frame1;
//	Mat frame2;
//	Mat frame3;
//	Mat test1;
//	Mat test2;
//	cvNamedWindow("Camera_Output1", 1);
//	cvNamedWindow("Camera_Output2", 1);
//	cvNamedWindow("Camera_Output3", 1);
//	capture.set(CV_CAP_PROP_EXPOSURE, 0.02);
//	
//	//capture.set(CV_CAP_PROP_EXPOSURE, 0.02);
//	capture >> frame1;
//	//if (waitKey(30) >= 0);
//	//capture.set(CV_CAP_PROP_EXPOSURE, 0.02);
//	capture >> frame2;
//	capture >> frame3;
//	cout << fps;
//	test1 = capture.grab();
//	
//	imshow("Camera_Output1", frame1);
//	imshow("Camera_Output2", frame2);
//	imshow("Camera_Output3", frame3);
//	//("test.png", frame3);
//
//	cv::waitKey(0);                 // hold windows open until user presses a key
//	//cvReleaseCapture(capture); //Release capture.
//	cvDestroyWindow("Camera_Output");
//
//	return(0);
//}


int main(int, char**)
{
	VideoCapture capture(0);
	VideoCapture capture2(0);
	capture.set(CV_CAP_PROP_FPS, 20);
	//capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	//capture2.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
	//capture2.set(CV_CAP_PROP_FRAME_WIDTH, 1280);

	Mat frame1;
	Mat frame2;
	Mat frame3;

	cvNamedWindow("Camera_Output1", 1);
	cvNamedWindow("Camera_Output2", 1);
	char key;
	int fps = 20;
	
	cout << capture.get(CV_CAP_PROP_EXPOSURE) << " " << capture2.get(CV_CAP_PROP_EXPOSURE);
	
	while(1)
	{

	capture.set(CV_CAP_PROP_EXPOSURE, -2.0);
	capture >> frame1;	
	imshow("Camera_Output1", frame1);
	cout << "Capture 1 " << capture.get(CV_CAP_PROP_EXPOSURE);
	cvWaitKey(50);


	capture2.set(CV_CAP_PROP_EXPOSURE, -5.0);
	capture2 >> frame2;
	imshow("Camera_Output2", frame2);
	cout <<"Capture 2 "<< capture2.get(CV_CAP_PROP_EXPOSURE) << endl;
	cvWaitKey(50);

	key = cvWaitKey(10);

  //Capture Keyboard stroke
	if (char(key) == 27) {
		cout << "Break";
		break;
		}
	}

	cvDestroyWindow("Camera_Output1");
	cvDestroyWindow("Camera_Output2");

	return(0);


}


//int main(int, char**)
//{
//	VideoCapture cap(0); // open the default camera
//	if (!cap.isOpened())  // check if we succeeded
//		return -1;
//
//	Mat edges;
//	namedWindow("edges", 1);
//	for (;;)
//	{
//		Mat frame;
//		cap >> frame; // get a new frame from camera
//		cvtColor(frame, edges, CV_BGR2GRAY);
//		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
//		Canny(edges, edges, 0, 30, 3);
//		imshow("edges", edges);
//		if (waitKey(30) >= 0) break;
//	}
//	// the camera will be deinitialized automatically in VideoCapture destructor
//	return 0;
//}
//int main()
//{
//	cvNamedWindow("Camera_Output", 1);    //Create window
//	CvCapture* capture = cvCaptureFromCAM(CV_CAP_ANY);  //Capture using any camera connected to your system
//	while (1) { //Create infinte loop for live streaming
//
//		IplImage* frame = cvQueryFrame(capture); //Create image frames from capture
//		cvShowImage("Camera_Output", frame);   //Show image frames on created window
//		key = cvWaitKey(10);     //Capture Keyboard stroke
//		if (char(key) == 27) {
//			cout << "Break";
//			break;      //If you hit ESC key loop will break.
//		}
//	}
//	cv::waitKey(0);
//	cvReleaseCapture(&capture); //Release capture.
//	cvDestroyWindow("Camera_Output"); //Destroy Window
//	return 0;
//}

