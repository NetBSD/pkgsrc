$NetBSD: patch-vncviewer_BaseTouchHandler.h,v 1.1 2024/08/27 07:31:13 wiz Exp $

Fix struct timeval.

--- vncviewer/BaseTouchHandler.h.orig	2024-08-27 07:20:49.287724400 +0000
+++ vncviewer/BaseTouchHandler.h
@@ -22,6 +22,8 @@
 
 #include "GestureEvent.h"
 
+#include <time.h>
+
 class BaseTouchHandler {
   public:
     virtual ~BaseTouchHandler();
