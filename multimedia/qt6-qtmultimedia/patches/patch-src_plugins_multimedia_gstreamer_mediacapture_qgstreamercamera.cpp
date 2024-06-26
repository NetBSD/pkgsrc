$NetBSD: patch-src_plugins_multimedia_gstreamer_mediacapture_qgstreamercamera.cpp,v 1.1 2024/06/26 16:41:00 adam Exp $

Fix build.

--- src/plugins/multimedia/gstreamer/mediacapture/qgstreamercamera.cpp.orig	2024-06-24 16:19:54.603259159 +0000
+++ src/plugins/multimedia/gstreamer/mediacapture/qgstreamercamera.cpp
@@ -718,6 +718,7 @@ int QGstreamerCamera::getV4L2Parameter(q
         return control.value;
     });
 }
+#endif
 
 QGstreamerCustomCamera::QGstreamerCustomCamera(QCamera *camera)
     : QGstreamerCameraBase{
@@ -766,6 +767,5 @@ void QGstreamerCustomCamera::setActive(b
     emit activeChanged(active);
 }
 
-#endif
 
 QT_END_NAMESPACE
