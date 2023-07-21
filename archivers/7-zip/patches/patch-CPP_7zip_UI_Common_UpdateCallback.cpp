$NetBSD: patch-CPP_7zip_UI_Common_UpdateCallback.cpp,v 1.1 2023/07/21 22:42:05 ryoon Exp $

* Fix NetBSD build.

--- CPP/7zip/UI/Common/UpdateCallback.cpp.orig	2023-06-26 07:32:05.662479141 +0000
+++ CPP/7zip/UI/Common/UpdateCallback.cpp
@@ -14,7 +14,7 @@ functions: gnu_dev_makedev(), gnu_dev_ma
 */
 // for major()/minor():
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(BSD) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(BSD) || defined(__APPLE__) || defined(__NetBSD__)
 #else
 #ifndef major
 #include <sys/sysmacros.h>
