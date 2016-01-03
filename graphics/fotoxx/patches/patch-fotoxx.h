$NetBSD: patch-fotoxx.h,v 1.1 2016/01/03 04:33:50 ryoon Exp $

--- fotoxx.h.orig	2016-01-01 08:20:29.000000000 +0000
+++ fotoxx.h
@@ -21,7 +21,9 @@
 
 *********************************************************************************/
 
+#if defined(__linux__)
 #include <wait.h>
+#endif
 #include <glob.h>
 #include <tiffio.h>
 #include <png.h>
