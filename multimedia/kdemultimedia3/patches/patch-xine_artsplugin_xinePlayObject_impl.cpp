$NetBSD: patch-xine_artsplugin_xinePlayObject_impl.cpp,v 1.1 2012/04/06 11:17:53 markd Exp $

Build with xine-1.2.  From trinity desktop.

--- xine_artsplugin/xinePlayObject_impl.cpp.orig	2005-09-10 08:20:09.000000000 +0000
+++ xine_artsplugin/xinePlayObject_impl.cpp
@@ -698,7 +698,7 @@ void xinePlayObject_impl::eventLoop()
 
 	    if (stream != 0)
 	    {
-		xine_gui_send_vo_data( stream,
+		xine_port_send_gui_data( vo_port,
 				       XINE_GUI_SEND_EXPOSE_EVENT,
 				       &event );
 	    }
@@ -714,7 +714,7 @@ void xinePlayObject_impl::eventLoop()
 
 	    if (stream != 0)
 	    {
-		xine_gui_send_vo_data( stream,
+		xine_port_send_gui_data( vo_port,
 				       XINE_GUI_SEND_COMPLETION_EVENT,
 				       &event );
 	    }
@@ -748,7 +748,7 @@ void xineVideoPlayObject_impl::x11Window
 	{
 	    resizeNotify();
 
-	    xine_gui_send_vo_data( stream,
+	    xine_port_send_gui_data( vo_port,
 				   XINE_GUI_SEND_DRAWABLE_CHANGED,
 				   (void *)window );
 	}
