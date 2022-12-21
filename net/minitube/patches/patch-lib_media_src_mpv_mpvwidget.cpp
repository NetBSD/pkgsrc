$NetBSD: patch-lib_media_src_mpv_mpvwidget.cpp,v 1.1 2022/12/21 14:58:15 wiz Exp $

Fix build with mpb 0.35.
https://github.com/freebsd/freebsd-ports/commit/ac9b20c88deb90ca6604c7a07f4e36f826bffd6c
via https://github.com/flaviotordini/minitube/issues/217

--- lib/media/src/mpv/mpvwidget.cpp.orig	2022-02-03 02:16:51.000000000 +0000
+++ lib/media/src/mpv/mpvwidget.cpp
@@ -30,7 +30,11 @@ void MpvWidget::initializeGL() {
     qDebug() << "initializeGL" << nativeParent;
     if (nativeParent == nullptr) qFatal("No native parent");
 
-    mpv_opengl_init_params gl_init_params{get_proc_address, this, nullptr};
+    #if MPV_CLIENT_API_VERSION < MPV_MAKE_VERSION(2,0)
+	mpv_opengl_init_params gl_init_params{get_proc_address, this, nullptr};
+    #else
+	mpv_opengl_init_params gl_init_params{get_proc_address, this};
+    #endif
     mpv_render_param params[]{{MPV_RENDER_PARAM_API_TYPE, (void *)MPV_RENDER_API_TYPE_OPENGL},
                               {MPV_RENDER_PARAM_OPENGL_INIT_PARAMS, &gl_init_params},
                               {MPV_RENDER_PARAM_INVALID, nullptr},
