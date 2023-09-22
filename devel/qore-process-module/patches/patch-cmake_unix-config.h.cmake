$NetBSD: patch-cmake_unix-config.h.cmake,v 1.1 2023/09/22 08:20:03 nros Exp $

* getloadavg is in sys/loadavg.h on Illumos

--- cmake/unix-config.h.cmake.orig	2018-09-11 08:17:59.000000000 +0000
+++ cmake/unix-config.h.cmake
@@ -1,2 +1,3 @@
 #cmakedefine HAVE_KILL
+#cmakedefine HAVE_SYS_LOADAVG_H
 
