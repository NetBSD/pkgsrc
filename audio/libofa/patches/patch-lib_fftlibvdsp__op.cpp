$NetBSD: patch-lib_fftlibvdsp__op.cpp,v 1.1 2015/11/21 17:36:10 adam Exp $

Fix building with newer OS X API.

--- lib/fftlibvdsp_op.cpp.orig	2015-11-21 17:32:57.000000000 +0000
+++ lib/fftlibvdsp_op.cpp
@@ -23,12 +23,12 @@ FFTLib_op::Initialize(int N, bool optimi
 	{
 		delete[] A.realp;
 		delete[] A.imagp;
-		destroy_fftsetupD(SetupReal);
+		vDSP_destroy_fftsetupD(SetupReal);
 	}
 		
 	A.realp = new double[ N/2];
 	A.imagp = new double[ N/2];
-	SetupReal = create_fftsetupD(Exp, 0);
+	SetupReal = vDSP_create_fftsetupD(Exp, 0);
 	Init = true;
 }
 
@@ -46,9 +46,9 @@ FFTLib_op::SetSize(int N, bool optimize,
 void 
 FFTLib_op::ComputeFrame(int N, double *in, double *out)
 {
-	ctozD ((DSPDoubleComplex*) in, 2, &A, 1, N/2 );
+	vDSP_ctozD((DSPDoubleComplex*) in, 2, &A, 1, N/2 );
 	
-	fft_zripD(SetupReal, &A, 1, Exp, FFT_FORWARD);
+	vDSP_fft_zripD(SetupReal, &A, 1, Exp, FFT_FORWARD);
 	
 	int i,j;
 	for (i=0; i<N/2; i++)
