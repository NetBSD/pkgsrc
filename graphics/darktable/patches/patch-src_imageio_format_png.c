$NetBSD: patch-src_imageio_format_png.c,v 1.1.1.1 2011/07/26 21:37:47 jakllsch Exp $

Needs a constant from zlib.

--- src/imageio/format/png.c.orig	2011-07-02 03:15:32.000000000 +0000
+++ src/imageio/format/png.c
@@ -27,6 +27,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <png.h>
+#include <zlib.h>
 #include <inttypes.h>
 
 DT_MODULE(1)
