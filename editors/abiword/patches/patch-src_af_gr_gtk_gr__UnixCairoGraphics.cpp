$NetBSD: patch-src_af_gr_gtk_gr__UnixCairoGraphics.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

Abiword bug 13791, SVN revision 35482: Disable double buffering on GTK3.

--- src/af/gr/gtk/gr_UnixCairoGraphics.cpp.orig	2016-10-21 00:39:16.000000000 +0000
+++ src/af/gr/gtk/gr_UnixCairoGraphics.cpp
@@ -126,8 +126,12 @@ GR_Graphics *   GR_UnixCairoGraphics::gr
 
 //	UT_return_val_if_fail(!info.isPrinterGraphics(), NULL);
 	GR_UnixCairoAllocInfo &AI = (GR_UnixCairoAllocInfo&)info;
-
+#if GTK_CHECK_VERSION(3,0,0)
+	// We disable double buffering on Gtk3 because it doesn't work.
+	return new GR_UnixCairoGraphics(AI.m_win, false);
+#else
 	return new GR_UnixCairoGraphics(AI.m_win, AI.m_double_buffered);
+#endif
 }
 
 inline UT_RGBColor _convertGdkColor(const GdkColor &c)
@@ -566,7 +570,10 @@ void GR_UnixCairoGraphics::_beginPaint()
 void GR_UnixCairoGraphics::_endPaint()
 {
 	if (m_CairoCreated)
+	{
+		cairo_surface_flush(cairo_get_target(m_cr));
 		cairo_destroy (m_cr);
+	}
 	m_cr = NULL;
 
 	m_Painting = false;
@@ -577,9 +584,17 @@ void GR_UnixCairoGraphics::_endPaint()
 
 void GR_UnixCairoGraphics::flush(void)
 {
+
 	if (m_Widget) {
 		gtk_widget_queue_draw(m_Widget);
 	}
+	
+/*
+	if(m_cr)
+	{
+		cairo_surface_flush(cairo_get_target(m_cr));
+	}
+*/
 }
 
 bool GR_UnixCairoGraphics::queryProperties(GR_Graphics::Properties gp) const
