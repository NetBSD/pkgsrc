$NetBSD: patch-src_imageio_format_png.c,v 1.2 2011/08/25 14:42:53 jakllsch Exp $

Needs a constant from zlib.

--- src/imageio/format/png.c.orig	2011-08-24 09:20:29.000000000 +0000
+++ src/imageio/format/png.c
@@ -27,6 +27,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <png.h>
+#include <zlib.h>
 #include <inttypes.h>
 
 DT_MODULE(1)
