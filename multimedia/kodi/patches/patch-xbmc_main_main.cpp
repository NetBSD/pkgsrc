$NetBSD: patch-xbmc_main_main.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/main/main.cpp.orig	2015-12-22 18:28:15.000000000 +0000
+++ xbmc/main/main.cpp
@@ -28,6 +28,7 @@
 #ifdef TARGET_POSIX
 #include <sys/resource.h>
 #include <signal.h>
+#include <locale.h>
 #endif
 #if defined(TARGET_DARWIN_OSX)
   #include "Util.h"
