$NetBSD: patch-src_viewarea.cpp,v 1.1 2021/08/31 12:06:22 markd Exp $

from FreeBSD port

--- src/viewarea.cpp.orig	2016-09-24 15:29:58.000000000 +0000
+++ src/viewarea.cpp
@@ -2535,7 +2535,7 @@ void VideoOutput::useIndirectWidget (boo
             if (!m_plain_window) {
                 xcb_screen_t* scr = m_view->viewArea()->d->screen_of_display(connection, QX11Info::appScreen());
                 m_plain_window = xcb_generate_id(connection);
-                uint32_t values[] = { scr->black_pixel, m_input_mask };
+                uint32_t values[] = { scr->black_pixel, static_cast<uint32_t>(m_input_mask) };
 #if QT_VERSION >= 0x050600
                 int devicew = (int)(width() * devicePixelRatioF());
                 int deviceh = (int)(height() * devicePixelRatioF());
