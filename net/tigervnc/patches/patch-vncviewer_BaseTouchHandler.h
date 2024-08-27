$NetBSD: patch-vncviewer_BaseTouchHandler.h,v 1.2 2024/08/27 07:33:11 wiz Exp $

Add header for struct timeval.
https://github.com/TigerVNC/tigervnc/pull/1824

--- vncviewer/BaseTouchHandler.h.orig	2024-08-27 07:20:49.287724400 +0000
+++ vncviewer/BaseTouchHandler.h
@@ -22,6 +22,8 @@
 
 #include "GestureEvent.h"
 
+#include <time.h>
+
 class BaseTouchHandler {
   public:
     virtual ~BaseTouchHandler();
