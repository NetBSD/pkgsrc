$NetBSD: patch-digikam_imageplugins_coreplugin_sharpnesseditor_clapack_f2c.h,v 1.1 2013/04/30 22:21:41 joerg Exp $

--- digikam/imageplugins/coreplugin/sharpnesseditor/clapack/f2c.h.orig	2013-04-30 19:42:00.000000000 +0000
+++ digikam/imageplugins/coreplugin/sharpnesseditor/clapack/f2c.h
@@ -154,10 +154,13 @@ struct Namelist {
 	};
 typedef struct Namelist Namelist;
 
+#ifndef __cplusplus
 #define abs(x) ((x) >= 0 ? (x) : -(x))
-#define dabs(x) (doublereal)abs(x)
 #define min(a,b) ((a) <= (b) ? (a) : (b))
 #define max(a,b) ((a) >= (b) ? (a) : (b))
+#endif
+
+#define dabs(x) (doublereal)abs(x)
 #define dmin(a,b) (doublereal)min(a,b)
 #define dmax(a,b) (doublereal)max(a,b)
 #define bit_test(a,b)	((a) >> (b) & 1)
