$NetBSD: patch-libmpdemux_demux__gif.c,v 1.3 2015/11/21 09:47:23 leot Exp $

* Fix build with giflib 5.1.

--- libmpdemux/demux_gif.c.orig	2014-10-05 02:39:08.000000000 +0000
+++ libmpdemux/demux_gif.c
@@ -44,6 +44,18 @@ typedef struct {
 } gif_priv_t;
 
 #define GIF_SIGNATURE (('G' << 16) | ('I' << 8) | 'F')
+ 
+/* from util/qprintf.c of giflib 5.0.4 */
+void
+PrintGifError(int ErrorCode)
+{
+    char *Err = GifErrorString(ErrorCode);
+
+    if (Err != NULL)
+	fprintf(stderr, "GIF-LIB error: %s.\n", Err);
+    else
+	fprintf(stderr, "GIF-LIB undefined error %d.\n", ErrorCode);
+}
 
 #if defined GIFLIB_MAJOR && GIFLIB_MAJOR >= 5
 #define DGifOpen(a, b) DGifOpen(a, b, NULL)
@@ -70,7 +82,7 @@ static void print_gif_error(GifFileType 
 #else
 static void print_gif_error(GifFileType *gif)
 {
-  PrintGifError();
+  PrintGifError(gif->Error);
 }
 #endif
 
