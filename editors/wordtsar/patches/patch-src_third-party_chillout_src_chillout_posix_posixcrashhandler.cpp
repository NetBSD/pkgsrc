$NetBSD: patch-src_third-party_chillout_src_chillout_posix_posixcrashhandler.cpp,v 1.1 2026/11/09 17:35:45 ryoon Exp $

--- src/third-party/chillout/src/chillout/posix/posixcrashhandler.cpp.orig	2026-11-09 08:43:35.666847062 +0000
+++ src/third-party/chillout/src/chillout/posix/posixcrashhandler.cpp
@@ -12,7 +12,7 @@
 #include <sstream>
 #include <memory>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 #include <unistd.h>
 #endif
 
