$NetBSD: patch-modules_gui_qt4_input__manager.cpp,v 1.2 2016/05/12 15:56:15 wiz Exp $

Qt's MOC doesn't handle int64_t, so introduce a meaningful type name
so that slot/signal/connection macros work properly.

--- modules/gui/qt4/input_manager.cpp.orig	2016-04-18 11:10:31.000000000 +0000
+++ modules/gui/qt4/input_manager.cpp
@@ -138,7 +138,7 @@ void InputManager::setInput( input_threa
                     !var_GetFloat( p_input, "start-time" ) &&
                     !var_GetFloat( p_input, "stop-time" ) )
             {
-                emit resumePlayback( (int64_t)i_time * 1000 );
+                emit resumePlayback( (putime_t)i_time * 1000 );
             }
             playlist_Lock( THEPL );
             // Add root items only
@@ -453,7 +453,7 @@ void InputManager::UpdatePosition()
 {
     /* Update position */
     int i_length;
-    int64_t i_time;
+    putime_t i_time;
     float f_pos;
     i_length = var_GetTime(  p_input , "length" ) / CLOCK_FREQ;
     i_time = var_GetTime(  p_input , "time");
@@ -995,21 +995,21 @@ void InputManager::setAtoB()
     {
         timeB = var_GetTime( THEMIM->getInput(), "time"  );
         var_SetTime( THEMIM->getInput(), "time" , timeA );
-        CONNECT( this, positionUpdated( float, int64_t, int ),
-                 this, AtoBLoop( float, int64_t, int ) );
+        CONNECT( this, positionUpdated( float, putime_t, int ),
+                 this, AtoBLoop( float, putime_t, int ) );
     }
     else
     {
         timeA = 0;
         timeB = 0;
-        disconnect( this, SIGNAL( positionUpdated( float, int64_t, int ) ),
-                    this, SLOT( AtoBLoop( float, int64_t, int ) ) );
+        disconnect( this, SIGNAL( positionUpdated( float, putime_t, int ) ),
+                    this, SLOT( AtoBLoop( float, putime_t, int ) ) );
     }
     emit AtoBchanged( (timeA != 0 ), (timeB != 0 ) );
 }
 
 /* Function called regularly when in an AtoB loop */
-void InputManager::AtoBLoop( float, int64_t i_time, int )
+void InputManager::AtoBLoop( float, putime_t i_time, int )
 {
     if( timeB && i_time >= timeB )
         var_SetTime( THEMIM->getInput(), "time" , timeA );
