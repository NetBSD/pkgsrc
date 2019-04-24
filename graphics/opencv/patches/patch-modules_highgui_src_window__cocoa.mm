$NetBSD: patch-modules_highgui_src_window__cocoa.mm,v 1.1 2019/04/24 19:34:45 adam Exp $

Explicitly cast int to double.

--- modules/highgui/src/window_cocoa.mm.orig	2019-04-24 11:04:32.000000000 +0000
+++ modules/highgui/src/window_cocoa.mm
@@ -266,7 +266,7 @@ CV_IMPL void cvResizeWindow( const char*
     CVWindow *window = cvGetWindow(name);
     if(window && ![window autosize]) {
         height += [window contentView].sliderHeight;
-        NSSize size = { width, height };
+        NSSize size = { double(width), double(height) };
         [window setContentSize:size];
     }
     [localpool drain];
