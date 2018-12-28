$NetBSD: patch-src_af_xap_gtk_xap__UnixFrameImpl.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13815, SVN revision 35394: Draw event should return TRUE.

Abiword bug 13791, SVN revision 35480: Fix flicker and caret problems.

--- src/af/xap/gtk/xap_UnixFrameImpl.cpp.orig	2014-12-14 14:56:47.000000000 +0000
+++ src/af/xap/gtk/xap_UnixFrameImpl.cpp
@@ -1208,15 +1208,23 @@ gint XAP_UnixFrameImpl::_fe::delete_even
 }
 
 #if GTK_CHECK_VERSION(3,0,0)
-gint XAP_UnixFrameImpl::_fe::draw(GtkWidget * w, cairo_t * cr)
+gboolean XAP_UnixFrameImpl::_fe::draw(GtkWidget * w, cairo_t * cr)
 #else
-gint XAP_UnixFrameImpl::_fe::expose(GtkWidget * w, GdkEventExpose* pExposeEvent)
+gboolean XAP_UnixFrameImpl::_fe::expose(GtkWidget * w, GdkEventExpose* pExposeEvent)
 #endif
 {
 	XAP_UnixFrameImpl * pUnixFrameImpl = static_cast<XAP_UnixFrameImpl *>(g_object_get_data(G_OBJECT(w), "user_data"));
 	FV_View * pView = static_cast<FV_View *>(pUnixFrameImpl->getFrame()->getCurrentView());
+	double x, y, width, height;
 #if GTK_CHECK_VERSION(3,0,0)
-	GdkEventExpose *pExposeEvent = reinterpret_cast<GdkEventExpose *>(gtk_get_current_event());
+	cairo_clip_extents (cr, &x, &y, &width, &height);
+	width -= x;
+	height -= y;
+#else
+	x = pExposeEvent->area.x;
+	y = pExposeEvent->area.y;
+	width = pExposeEvent->area.width;
+	height = pExposeEvent->area.height;
 #endif
 /* Jean: commenting out next lines since the zoom update code does draw only
  * part of what needs to be updated. */
@@ -1231,19 +1239,21 @@ gint XAP_UnixFrameImpl::_fe::expose(GtkW
 		if (pGr->getPaintCount () > 0)
 			return TRUE;
 		xxx_UT_DEBUGMSG(("Expose area: x %d y %d width %d  height %d \n",pExposeEvent->area.x,pExposeEvent->area.y,pExposeEvent->area.width,pExposeEvent->area.height));
-		rClip.left = pGr->tlu(pExposeEvent->area.x);
-		rClip.top = pGr->tlu(pExposeEvent->area.y);
-		rClip.width = pGr->tlu(pExposeEvent->area.width)+1;
-		rClip.height = pGr->tlu(pExposeEvent->area.height)+1;
+		rClip.left = pGr->tlu(x);
+		rClip.top = pGr->tlu(y);
 #if GTK_CHECK_VERSION(3,0,0)
+		rClip.width = pGr->tlu(width);
+		rClip.height = pGr->tlu(height);
 		static_cast<GR_CairoGraphics *>(pGr)->setCairo(cr);
 		pView->draw(&rClip);
 		static_cast<GR_CairoGraphics *>(pGr)->setCairo(NULL);
 #else
+		rClip.width = pGr->tlu(width)+1;
+		rClip.height = pGr->tlu(height)+1;
 		pView->draw(&rClip);
 #endif
 	}
-	return FALSE;
+	return TRUE;
 }
 
 static bool bScrollWait = false;
