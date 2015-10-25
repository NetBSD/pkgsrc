$NetBSD: patch-modules_gui_qt4_util_input__slider.cpp,v 1.1 2015/10/25 11:00:18 wiz Exp $

Qt's MOC doesn't handle int64_t, so introduce a meaningful type name
so that slot/signal/connection macros work properly.

--- modules/gui/qt4/util/input_slider.cpp.orig	2015-04-12 15:12:46.000000000 +0000
+++ modules/gui/qt4/util/input_slider.cpp
@@ -164,7 +164,7 @@ void SeekSlider::setChapters( SeekPoints
  * \param time Elapsed time. Unused
  * \param legnth Duration time.
  ***/
-void SeekSlider::setPosition( float pos, int64_t time, int length )
+void SeekSlider::setPosition( float pos, putime_t time, int length )
 {
     VLC_UNUSED(time);
     if( pos == -1.0 )
