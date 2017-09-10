$NetBSD: patch-qt_src_3rdparty_webkit_Source_WebCore_html_HTMLImageElement.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/WebCore/html/HTMLImageElement.cpp.orig	2016-08-23 06:13:30.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/WebCore/html/HTMLImageElement.cpp
@@ -74,7 +74,7 @@ PassRefPtr<HTMLImageElement> HTMLImageEl
     RefPtr<HTMLImageElement> image = adoptRef(new HTMLImageElement(imgTag, document));
     if (optionalWidth)
         image->setWidth(*optionalWidth);
-    if (optionalHeight > 0)
+    if (optionalHeight)
         image->setHeight(*optionalHeight);
     return image.release();
 }
