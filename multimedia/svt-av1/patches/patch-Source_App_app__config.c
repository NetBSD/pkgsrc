$NetBSD: patch-Source_App_app__config.c,v 1.2 2026/08/12 03:41:38 ryoon Exp $

Re-order includes so that FOPEN override works.

--- Source/App/app_config.c.orig	2026-03-23 06:52:18.000000000 +0000
+++ Source/App/app_config.c
@@ -20,10 +20,6 @@
 #include <ctype.h>
 #include <sys/stat.h>
 
-#include "EbSvtAv1Metadata.h"
-#include "app_config.h"
-#include "app_context.h"
-#include "app_input_y4m.h"
 #ifdef _WIN32
 #include <windows.h>
 #include <io.h>
@@ -32,6 +28,9 @@
 #include <sys/file.h>
 #endif
 
+#include "EbSvtAv1Metadata.h"
+#include "app_input_y4m.h"
+#include "app_context.h"
 #include "app_output_ivf.h"
 #if !defined(_WIN32) || !defined(HAVE_STRNLEN_S)
 #include "third_party/safestringlib/safe_str_lib.h"
