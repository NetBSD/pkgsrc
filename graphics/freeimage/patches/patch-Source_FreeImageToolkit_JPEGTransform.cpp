$NetBSD: patch-Source_FreeImageToolkit_JPEGTransform.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImageToolkit/JPEGTransform.cpp.orig	2015-03-04 00:07:10.000000000 +0000
+++ Source/FreeImageToolkit/JPEGTransform.cpp
@@ -26,10 +26,10 @@ extern "C" {
 #undef FAR
 #include <setjmp.h>
 
-#include "../LibJPEG/jinclude.h"
-#include "../LibJPEG/jpeglib.h"
-#include "../LibJPEG/jerror.h"
-#include "../LibJPEG/transupp.h"
+#include <jinclude.h>
+#include <jpeglib.h>
+#include <jerror.h>
+#include <transupp.h>
 }
 
 #include "FreeImage.h"
