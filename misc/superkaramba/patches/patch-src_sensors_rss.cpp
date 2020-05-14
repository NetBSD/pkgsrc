$NetBSD: patch-src_sensors_rss.cpp,v 1.1 2020/05/14 19:20:17 joerg Exp $

--- src/sensors/rss.cpp.orig	2020-05-13 22:19:59.121304123 +0000
+++ src/sensors/rss.cpp
@@ -79,7 +79,7 @@ void RssSensor::update()
             if (!n.isNull()) {
                 QDomNodeList links = docElem.elementsByTagName("link");
                 QDomNodeList displays;
-                if (format.contains("%d", Qt::CaseInsensitive) > 0) {
+                if (format.contains("%d", Qt::CaseInsensitive)) {
                     displays = docElem.elementsByTagName("description");
                 } else {
                     displays = docElem.elementsByTagName("title");
