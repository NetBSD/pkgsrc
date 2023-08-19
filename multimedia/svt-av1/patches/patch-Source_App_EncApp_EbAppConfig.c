$NetBSD: patch-Source_App_EncApp_EbAppConfig.c,v 1.1 2023/08/19 15:03:39 jperkin Exp $

Re-order includes to avoid FOPEN redefine.

--- Source/App/EncApp/EbAppConfig.c.orig	2023-04-26 22:11:56.000000000 +0000
+++ Source/App/EncApp/EbAppConfig.c
@@ -16,10 +16,6 @@
 #include <ctype.h>
 #include <sys/stat.h>
 
-#include "EbSvtAv1Metadata.h"
-#include "EbAppConfig.h"
-#include "EbAppContext.h"
-#include "EbAppInputy4m.h"
 #ifdef _WIN32
 #include <windows.h>
 #include <io.h>
@@ -28,6 +24,10 @@
 #include <sys/file.h>
 #endif
 
+#include "EbSvtAv1Metadata.h"
+#include "EbAppConfig.h"
+#include "EbAppContext.h"
+#include "EbAppInputy4m.h"
 #include "EbAppOutputivf.h"
 
 #if !defined(_WIN32) || !defined(HAVE_STRNLEN_S)
