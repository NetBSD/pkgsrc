$NetBSD: patch-pdfium_third__party_libtiff_tif__pixarlog.c,v 1.1 2023/09/09 09:49:56 nros Exp $

use pkgsrc zlib

--- pdfium/third_party/libtiff/tif_pixarlog.c.orig	2023-09-08 21:11:51.774327127 +0000
+++ pdfium/third_party/libtiff/tif_pixarlog.c
@@ -90,7 +90,7 @@
  */
 
 #include "tif_predict.h"
-#include "../zlib_v128/zlib.h"
+#include <zlib.h>
 
 #include <stdio.h>
 #include <stdlib.h>
