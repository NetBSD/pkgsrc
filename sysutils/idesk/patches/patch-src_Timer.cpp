$NetBSD: patch-src_Timer.cpp,v 1.1 2024/10/10 19:21:10 nia Exp $

SunOS needs <string.h> for memset as used by FD_ZERO.

--- src/Timer.cpp.orig	2024-10-10 19:19:17.820759237 +0000
+++ src/Timer.cpp
@@ -25,6 +25,7 @@
 
 #include "Database.h"
 #include <X11/Xlib.h>
+#include <cstring>
 #include "Timer.h"
 
 vector<TimerControl*> Timer::items;
