$NetBSD: patch-lib_gif__lib.h,v 1.1 2013/08/13 10:20:47 joerg Exp $

Pull in correct header for size_t.

--- lib/gif_lib.h.orig	2013-08-12 16:47:43.000000000 +0000
+++ lib/gif_lib.h
@@ -19,6 +19,7 @@ extern "C" {
 #define GIF_OK      1
 
 #include <stdbool.h>
+#include <stddef.h>
 
 #define GIF_STAMP "GIFVER"          /* First chars in file - GIF stamp.  */
 #define GIF_STAMP_LEN sizeof(GIF_STAMP) - 1
