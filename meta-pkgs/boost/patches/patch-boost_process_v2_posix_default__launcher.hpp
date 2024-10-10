$NetBSD: patch-boost_process_v2_posix_default__launcher.hpp,v 1.1 2024/10/10 14:44:17 jperkin Exp $

Fix SunOS.

--- boost/process/v2/posix/default_launcher.hpp.orig	2024-10-10 13:01:55.403121250 +0000
+++ boost/process/v2/posix/default_launcher.hpp
@@ -29,7 +29,7 @@
 #include <unistd.h>
 
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__MACH__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__MACH__) || defined(__sun)
 extern "C" { extern char **environ; }
 #endif
 
