$NetBSD: patch-src_konfigurator_savehelper.cpp,v 1.1 2018/05/17 11:04:19 jperkin Exp $

SunOS does not have __uid_t.

--- src/konfigurator/savehelper.cpp.orig	2014-10-09 07:07:50.000000000 +0000
+++ src/konfigurator/savehelper.cpp
@@ -22,7 +22,7 @@
 #include <kdebug.h>
 #include <unistd.h>
 
-#if defined(Q_CC_MSVC)
+#if defined(Q_CC_MSVC) || defined(__sun)
 // TODO: or rather use uid_t in the getuid() call below?
 #define __uid_t uid_t
 #endif
