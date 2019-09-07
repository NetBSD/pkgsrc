$NetBSD: patch-Source_UI_os.h,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- add NetBSD denitions

--- Source/UI/os.h.orig	2015-06-07 13:33:50.000000000 +0000
+++ Source/UI/os.h
@@ -31,6 +31,7 @@
 // Linux
 //
 #if defined(__linux__) && !defined(__ANDROID__)
+#define UNIX
 #include <SDL2/SDL.h>
 #include <stdio.h>
 #include <string.h>
@@ -38,9 +39,21 @@
 #endif // __linux__ && !__ANDROID__
 
 //
+// NetBSD
+//
+#if  defined(__NetBSD__)
+#define UNIX
+#include <SDL.h>
+#include <stdio.h>
+#include <string.h>
+#include <time.h>
+#endif // __NetBSD__
+
+//
 // Android
 //
 #ifdef __ANDROID__
+#define UNIX
 #include "SDL.h"
 #include <stdio.h>
 #include <string.h>
