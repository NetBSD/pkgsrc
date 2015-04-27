$NetBSD: patch-lib-src_libnyquist_nyquist_ffts_src_fftlib.c,v 1.1 2015/04/27 23:50:39 joerg Exp $

--- lib-src/libnyquist/nyquist/ffts/src/fftlib.c.orig	2015-03-02 01:07:22.000000000 +0000
+++ lib-src/libnyquist/nyquist/ffts/src/fftlib.c
@@ -61,8 +61,8 @@ for (i1 = 0; i1 < Nroot_1; i1++){
 parts of ffts1
 *************************************************/
 
-inline void bitrevR2(float *ioptr, long M, short *BRLow);
-inline void bitrevR2(float *ioptr, long M, short *BRLow){
+void bitrevR2(float *ioptr, long M, short *BRLow);
+void bitrevR2(float *ioptr, long M, short *BRLow){
 /*** bit reverse and first radix 2 stage of forward or inverse fft ***/
 float	f0r;
 float	f0i;
@@ -198,8 +198,8 @@ for (; ioptr < iolimit; ioptr += POW2(M/
 };
 }
 
-inline void fft2pt(float *ioptr);
-inline void fft2pt(float *ioptr){
+void fft2pt(float *ioptr);
+void fft2pt(float *ioptr){
 /***   RADIX 2 fft	***/
 float f0r, f0i, f1r, f1i;
 float t0r, t0i;
@@ -229,8 +229,8 @@ ioptr[3] = f1i;
 }
 
 
-inline void fft4pt(float *ioptr);
-inline void fft4pt(float *ioptr){
+void fft4pt(float *ioptr);
+void fft4pt(float *ioptr){
 /***   RADIX 4 fft	***/
 float f0r, f0i, f1r, f1i, f2r, f2i, f3r, f3i;
 float t0r, t0i, t1r, t1i;
@@ -284,8 +284,8 @@ ioptr[6] = f3r;
 ioptr[7] = f3i;
 }
 
-inline void fft8pt(float *ioptr);
-inline void fft8pt(float *ioptr){
+void fft8pt(float *ioptr);
+void fft8pt(float *ioptr){
 /***   RADIX 8 fft	***/
 float w0r = 1.0/MYROOT2; /* cos(pi/4)	*/
 float f0r, f0i, f1r, f1i, f2r, f2i, f3r, f3i;
@@ -403,8 +403,8 @@ ioptr[14] = f6r;
 ioptr[15] = f6i;
 }
 
-inline void bfR2(float *ioptr, long M, long NDiffU);
-inline void bfR2(float *ioptr, long M, long NDiffU){
+void bfR2(float *ioptr, long M, long NDiffU);
+void bfR2(float *ioptr, long M, long NDiffU){
 /*** 2nd radix 2 stage ***/
 unsigned long	pos;
 unsigned long	posi;
@@ -512,8 +512,8 @@ for (SameUCnt = NSameU; SameUCnt > 0 ; S
 }
 }
 
-inline void bfR4(float *ioptr, long M, long NDiffU);
-inline void bfR4(float *ioptr, long M, long NDiffU){
+void bfR4(float *ioptr, long M, long NDiffU);
+void bfR4(float *ioptr, long M, long NDiffU){
 /*** 1 radix 4 stage ***/
 unsigned long	pos;
 unsigned long	posi;
@@ -721,8 +721,8 @@ f4i = f4i * Two - f6i;
 
 }
 
-inline void bfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt);
-inline void bfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt){
+void bfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt);
+void bfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt){
 /***   RADIX 8 Stages	***/
 unsigned long	pos;
 unsigned long	posi;
@@ -1125,8 +1125,8 @@ default:
 parts of iffts1
 *************************************************/
 
-inline void scbitrevR2(float *ioptr, long M, short *BRLow, float scale);
-inline void scbitrevR2(float *ioptr, long M, short *BRLow, float scale){
+void scbitrevR2(float *ioptr, long M, short *BRLow, float scale);
+void scbitrevR2(float *ioptr, long M, short *BRLow, float scale){
 /*** scaled bit reverse and first radix 2 stage forward or inverse fft ***/
 float	f0r;
 float	f0i;
@@ -1262,8 +1262,8 @@ for (; ioptr < iolimit; ioptr += POW2(M/
 };
 }
 
-inline void ifft2pt(float *ioptr, float scale);
-inline void ifft2pt(float *ioptr, float scale){
+void ifft2pt(float *ioptr, float scale);
+void ifft2pt(float *ioptr, float scale){
 /***   RADIX 2 ifft	***/
 float f0r, f0i, f1r, f1i;
 float t0r, t0i;
@@ -1292,8 +1292,8 @@ ioptr[2] = scale*f1r;
 ioptr[3] = scale*f1i;
 }
 
-inline void ifft4pt(float *ioptr, float scale);
-inline void ifft4pt(float *ioptr, float scale){
+void ifft4pt(float *ioptr, float scale);
+void ifft4pt(float *ioptr, float scale){
 /***   RADIX 4 ifft	***/
 float f0r, f0i, f1r, f1i, f2r, f2i, f3r, f3i;
 float t0r, t0i, t1r, t1i;
@@ -1347,8 +1347,8 @@ ioptr[6] = scale*f3r;
 ioptr[7] = scale*f3i;
 }
 
-inline void ifft8pt(float *ioptr, float scale);
-inline void ifft8pt(float *ioptr, float scale){
+void ifft8pt(float *ioptr, float scale);
+void ifft8pt(float *ioptr, float scale){
 /***   RADIX 8 ifft	***/
 float w0r = 1.0/MYROOT2; /* cos(pi/4)	*/
 float f0r, f0i, f1r, f1i, f2r, f2i, f3r, f3i;
@@ -1467,8 +1467,8 @@ ioptr[14] = scale*f6r;
 ioptr[15] = scale*f6i;
 }
 
-inline void ibfR2(float *ioptr, long M, long NDiffU);
-inline void ibfR2(float *ioptr, long M, long NDiffU){
+void ibfR2(float *ioptr, long M, long NDiffU);
+void ibfR2(float *ioptr, long M, long NDiffU){
 /*** 2nd radix 2 stage ***/
 unsigned long	pos;
 unsigned long	posi;
@@ -1576,8 +1576,8 @@ for (SameUCnt = NSameU; SameUCnt > 0 ; S
 }
 }
 
-inline void ibfR4(float *ioptr, long M, long NDiffU);
-inline void ibfR4(float *ioptr, long M, long NDiffU){
+void ibfR4(float *ioptr, long M, long NDiffU);
+void ibfR4(float *ioptr, long M, long NDiffU){
 /*** 1 radix 4 stage ***/
 unsigned long	pos;
 unsigned long	posi;
@@ -1785,8 +1785,8 @@ f4i = f4i * Two - f6i;
 
 }
 
-inline void ibfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt);
-inline void ibfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt){
+void ibfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt);
+void ibfstages(float *ioptr, long M, float *Utbl, long Ustride, long NDiffU, long StageCnt){
 /***   RADIX 8 Stages	***/
 unsigned long	pos;
 unsigned long	posi;
@@ -2193,8 +2193,8 @@ default:
 parts of rffts1
 *************************************************/
 
-inline void rfft1pt(float *ioptr);
-inline void rfft1pt(float *ioptr){
+void rfft1pt(float *ioptr);
+void rfft1pt(float *ioptr){
 /***   RADIX 2 rfft	***/
 float f0r, f0i;
 float t0r, t0i;
@@ -2212,8 +2212,8 @@ ioptr[0] = t0r;
 ioptr[1] = t0i;
 }
 
-inline void rfft2pt(float *ioptr);
-inline void rfft2pt(float *ioptr){
+void rfft2pt(float *ioptr);
+void rfft2pt(float *ioptr){
 /***   RADIX 4 rfft	***/
 float f0r, f0i, f1r, f1i;
 float t0r, t0i;
@@ -2245,8 +2245,8 @@ ioptr[2] = f1r;
 ioptr[3] = f1i;
 }
 
-inline void rfft4pt(float *ioptr);
-inline void rfft4pt(float *ioptr){
+void rfft4pt(float *ioptr);
+void rfft4pt(float *ioptr){
 /***   RADIX 8 rfft	***/
 float f0r, f0i, f1r, f1i, f2r, f2i, f3r, f3i;
 float t0r, t0i, t1r, t1i;
@@ -2318,8 +2318,8 @@ ioptr[6] = scale*f3r;
 ioptr[7] = scale*f3i;
 }
 
-inline void rfft8pt(float *ioptr);
-inline void rfft8pt(float *ioptr){
+void rfft8pt(float *ioptr);
+void rfft8pt(float *ioptr){
 /***   RADIX 16 rfft	***/
 float w0r = 1.0/MYROOT2; /* cos(pi/4)	*/
 float w1r = MYCOSPID8; /* cos(pi/8)	*/
@@ -2477,8 +2477,8 @@ ioptr[14] = scale*f6r;
 ioptr[15] = scale*f6i;
 }
 
-inline void frstage(float *ioptr, long M, float *Utbl);
-inline void frstage(float *ioptr, long M, float *Utbl){
+void frstage(float *ioptr, long M, float *Utbl);
+void frstage(float *ioptr, long M, float *Utbl){
 /*	Finish RFFT		*/
 
 unsigned long 	pos;
@@ -2687,8 +2687,8 @@ default:
 parts of riffts1
 *************************************************/
 
-inline void rifft1pt(float *ioptr, float scale);
-inline void rifft1pt(float *ioptr, float scale){
+void rifft1pt(float *ioptr, float scale);
+void rifft1pt(float *ioptr, float scale){
 /***   RADIX 2 rifft	***/
 float f0r, f0i;
 float t0r, t0i;
@@ -2706,8 +2706,8 @@ ioptr[0] = scale*t0r;
 ioptr[1] = scale*t0i;
 }
 
-inline void rifft2pt(float *ioptr, float scale);
-inline void rifft2pt(float *ioptr, float scale){
+void rifft2pt(float *ioptr, float scale);
+void rifft2pt(float *ioptr, float scale){
 /***   RADIX 4 rifft	***/
 float f0r, f0i, f1r, f1i;
 float t0r, t0i;
@@ -2740,8 +2740,8 @@ ioptr[2] = scale*f1r;
 ioptr[3] = scale*f1i;
 }
 
-inline void rifft4pt(float *ioptr, float scale);
-inline void rifft4pt(float *ioptr, float scale){
+void rifft4pt(float *ioptr, float scale);
+void rifft4pt(float *ioptr, float scale){
 /***   RADIX 8 rifft	***/
 float f0r, f0i, f1r, f1i, f2r, f2i, f3r, f3i;
 float t0r, t0i, t1r, t1i;
@@ -2811,8 +2811,8 @@ ioptr[6] = scale*f3r;
 ioptr[7] = scale*f3i;
 }
 
-inline void rifft8pt(float *ioptr, float scale);
-inline void rifft8pt(float *ioptr, float scale){
+void rifft8pt(float *ioptr, float scale);
+void rifft8pt(float *ioptr, float scale){
 /***   RADIX 16 rifft	***/
 float w0r = 1.0/MYROOT2; /* cos(pi/4)	*/
 float w1r = MYCOSPID8; /* cos(pi/8)	*/
@@ -2968,8 +2968,8 @@ ioptr[14] = scale*f6r;
 ioptr[15] = scale*f6i;
 }
 
-inline void ifrstage(float *ioptr, long M, float *Utbl);
-inline void ifrstage(float *ioptr, long M, float *Utbl){
+void ifrstage(float *ioptr, long M, float *Utbl);
+void ifrstage(float *ioptr, long M, float *Utbl){
 /*	Start RIFFT		*/
 
 unsigned long 	pos;
