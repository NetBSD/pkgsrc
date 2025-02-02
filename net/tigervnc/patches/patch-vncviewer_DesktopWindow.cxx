$NetBSD: patch-vncviewer_DesktopWindow.cxx,v 1.1 2025/02/02 16:23:06 wiz Exp $

A method Fl__Window::maximize() was added in FLTK 1.4, it should not be
called by this code written for FLTK 1.3.
<https://github.com/TigerVNC/tigervnc/pull/1887>

--- vncviewer/DesktopWindow.cxx.orig	2024-10-22 13:45:27.000000000 +0000
+++ vncviewer/DesktopWindow.cxx
@@ -174,7 +174,7 @@ DesktopWindow::DesktopWindow(int w, int 
 #ifdef __APPLE__
   // On OS X we can do the maximize thing properly before the
   // window is showned. Other platforms handled further down...
-  if (maximize) {
+  if (::maximize) {
     int dummy;
     Fl::screen_work_area(dummy, dummy, w, h, geom_x, geom_y);
   }
@@ -208,7 +208,7 @@ DesktopWindow::DesktopWindow(int w, int 
   // maximized property on Windows and X11 before showing the window.
   // See STR #2083 and STR #2178
 #ifndef __APPLE__
-  if (maximize) {
+  if (::maximize) {
     maximizeWindow();
   }
 #endif
