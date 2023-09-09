$NetBSD: patch-pdfium_third__party_libtiff_tif__zip.c,v 1.1 2023/09/09 09:49:56 nros Exp $

use pkgsrc zlib

--- pdfium/third_party/libtiff/tif_zip.c.orig	2023-09-08 21:12:11.638227521 +0000
+++ pdfium/third_party/libtiff/tif_zip.c
@@ -47,7 +47,7 @@
  * last found at ftp://ftp.uu.net/pub/archiving/zip/zlib/zlib-0.99.tar.gz.
  */
 #include "tif_predict.h"
-#include "../zlib_v128/zlib.h"
+#include <zlib.h>
 
 #include <stdio.h>
 
