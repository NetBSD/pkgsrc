$NetBSD: patch-Extensions_jpeg.c,v 1.1 2020/05/03 14:49:30 rillig Exp $

jpeg.c:774:17: error: array subscript has type 'char' [-Werror=char-subscripts]
    getbits(8, qt[zz[i]]);

Since zz only contains small numbers, the code is ok.

--- Extensions/jpeg.c.orig	1998-01-03 12:46:25.000000000 +0000
+++ Extensions/jpeg.c
@@ -198,7 +198,7 @@ static unsigned char JPEG_CAC_HuffVals[]
 #define JPEG_EXTEND(v, t) \
   ((v) < (1 << (t-1) ) ? (v) + (((-1) << t) + 1) : (v))
 
-static const char zz[] = { 0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18,
+static const unsigned char zz[] = { 0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18,
 			       11, 4, 5, 12, 19, 26, 33, 40, 48, 41, 34,
 			       27, 20, 13, 6, 7, 14, 21, 28, 35, 42, 49,
 			       56, 57, 50, 43, 36, 29, 22, 15, 23, 30,
