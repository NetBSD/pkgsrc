$NetBSD: patch-src_display_window.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/display/window.cc.orig	2013-05-03 22:49:02.000000000 +0000
+++ src/display/window.cc
@@ -40,6 +40,14 @@
 
 #include "window.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace display {
 
 Window::SlotTimer  Window::m_slotSchedule;
@@ -59,7 +67,7 @@ Window::Window(Canvas* canvas, int flags
   m_maxWidth(maxWidth),
   m_maxHeight(maxHeight) {
 
-  m_taskUpdate.slot() = std::tr1::bind(&Window::redraw, this);
+  m_taskUpdate.slot() = bind(&Window::redraw, this);
 }
 
 Window::~Window() {
