$NetBSD: patch-src_image.c,v 1.1 2014/06/29 18:07:30 dholland Exp $

Fix build with giflib 5.1.

--- src/image.c.orig	2013-12-31 19:06:18.000000000 +0000
+++ src/image.c
@@ -7289,7 +7289,7 @@ init_gif_functions (void)
 
 #else
 
-#define fn_DGifCloseFile	DGifCloseFile
+#define fn_DGifCloseFile(gf)	DGifCloseFile((gf), NULL)
 #define fn_DGifSlurp		DGifSlurp
 #define fn_DGifOpen		DGifOpen
 #define fn_DGifOpenFileName	DGifOpenFileName
