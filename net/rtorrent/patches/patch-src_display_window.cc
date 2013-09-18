$NetBSD: patch-src_display_window.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/display/window.cc.orig	2012-02-14 03:32:01.000000000 +0000
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
