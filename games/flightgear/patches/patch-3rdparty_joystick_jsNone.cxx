$NetBSD: patch-3rdparty_joystick_jsNone.cxx,v 1.1 2018/12/04 03:56:27 nia Exp $

TRUE is undefined...

--- 3rdparty/joystick/jsNone.cxx.orig	2018-06-03 18:56:53.000000000 +0000
+++ 3rdparty/joystick/jsNone.cxx
@@ -27,20 +27,20 @@ struct os_specific_s ;
 
 void jsJoystick::open ()
 {
-  error = TRUE ;
+  error = JS_TRUE ;
   num_axes = num_buttons = 0 ;
 }
 
 
 void jsJoystick::close ()
 {
-  error = TRUE ;
+  error = JS_TRUE ;
 }
 
 
 jsJoystick::jsJoystick ( int ident )
 {
-  error = TRUE ;
+  error = JS_TRUE ;
   num_axes = num_buttons = 0 ;
   os = NULL;
 }
