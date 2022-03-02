$NetBSD: patch-src_include_a68g-platform.h,v 1.1 2022/03/02 01:41:34 ryoon Exp $

* Fix *BSD compiler runtime error.

--- src/include/a68g-platform.h.orig	2022-02-01 20:45:41.000000000 +0000
+++ src/include/a68g-platform.h
@@ -24,8 +24,6 @@
 
 #if defined (BUILD_WIN32)
 #include "a68g-config.win32.h"
-#elif defined (BUILD_BSD)
-#include "a68g-config.bsd.h"
 #else
 #include "a68g-config.h"
 #endif
