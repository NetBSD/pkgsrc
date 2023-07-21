$NetBSD: patch-CPP_7zip_Common_FileStreams.cpp,v 1.1 2023/07/21 22:42:05 ryoon Exp $

* Fix NetBSD build.

--- CPP/7zip/Common/FileStreams.cpp.orig	2023-06-26 07:32:05.420332662 +0000
+++ CPP/7zip/Common/FileStreams.cpp
@@ -13,7 +13,7 @@
 
 // for major()/minor():
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(BSD) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(BSD) || defined(__APPLE__) || defined(__NetBSD__)
 #else
 #ifndef major
 #include <sys/sysmacros.h>
