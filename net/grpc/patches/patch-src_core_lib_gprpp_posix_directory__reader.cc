$NetBSD: patch-src_core_lib_gprpp_posix_directory__reader.cc,v 1.2 2024/09/12 13:14:15 wiz Exp $

Add NetBSD support.
https://github.com/grpc/grpc/pull/37700

--- src/core/lib/gprpp/posix/directory_reader.cc.orig	2024-09-12 12:38:10.451743828 +0000
+++ src/core/lib/gprpp/posix/directory_reader.cc
@@ -25,7 +25,7 @@
 #include <grpc/support/port_platform.h>
 
 #if defined(GPR_LINUX) || defined(GPR_ANDROID) || defined(GPR_FREEBSD) || \
-    defined(GPR_APPLE)
+    defined(GPR_APPLE) || defined(GPR_NETBSD)
 
 #include <dirent.h>
 
