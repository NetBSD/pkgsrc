$NetBSD: patch-src_framework_ui_graphicsapiprovider.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD.

--- src/framework/ui/graphicsapiprovider.cpp.orig	2025-07-21 11:40:48.337438095 +0000
+++ src/framework/ui/graphicsapiprovider.cpp
@@ -56,7 +56,7 @@ static const std::vector<GraphicsApi > A
 };
 #endif
 
-#ifdef Q_OS_FREEBSD
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 static const std::vector<GraphicsApi > ALLOWED_APIS = {
     GraphicsApi::OpenGL,
     GraphicsApi::Software
