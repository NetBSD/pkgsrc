$NetBSD: patch-src_platform_qt_InputController.cpp,v 1.1 2021/05/04 14:19:17 nia Exp $

Fix building without Qt5Multimedia.

--- src/platform/qt/InputController.cpp.orig	2021-04-19 04:47:22.000000000 +0000
+++ src/platform/qt/InputController.cpp
@@ -94,7 +94,6 @@ InputController::InputController(int pla
 		InputControllerImage* image = static_cast<InputControllerImage*>(context);
 		image->w = w;
 		image->h = h;
-		image->p->m_cameraActive = true;
 		if (image->image.isNull()) {
 			image->image.load(":/res/no-cam.png");
 		}
@@ -103,6 +102,7 @@ InputController::InputController(int pla
 		if (!camera.isNull()) {
 			image->p->m_cameraDevice = camera;
 		}
+		image->p->m_cameraActive = true;
 		QMetaObject::invokeMethod(image->p, "setupCam");
 #endif
 	};
