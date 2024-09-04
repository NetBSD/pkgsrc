$NetBSD: patch-Source_App_app__config.c,v 1.1 2024/09/04 11:59:05 jperkin Exp $

Re-order includes so that FOPEN override works.

--- Source/App/app_config.c.orig	2024-09-04 11:26:07.821209504 +0000
+++ Source/App/app_config.c
@@ -16,10 +16,6 @@
 #include <ctype.h>
 #include <sys/stat.h>
 
-#include "EbSvtAv1Metadata.h"
-#include "app_config.h"
-#include "app_context.h"
-#include "app_input_y4m.h"
 #ifdef _WIN32
 #include <windows.h>
 #include <io.h>
@@ -28,6 +24,9 @@
 #include <sys/file.h>
 #endif
 
+#include "EbSvtAv1Metadata.h"
+#include "app_input_y4m.h"
+#include "app_context.h"
 #include "app_output_ivf.h"
 
 #if !defined(_WIN32) || !defined(HAVE_STRNLEN_S)
