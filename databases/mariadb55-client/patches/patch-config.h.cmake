$NetBSD: patch-config.h.cmake,v 1.1 2015/05/07 12:45:29 fhajny Exp $

--- config.h.cmake.orig	2015-02-13 12:07:00.000000000 +0000
+++ config.h.cmake
@@ -126,6 +126,7 @@
 #cmakedefine HAVE_HIST_ENTRY 1
 #cmakedefine USE_LIBEDIT_INTERFACE 1
 #cmakedefine USE_NEW_READLINE_INTERFACE 1
+#cmakedefine USE_READLINE_V6 1
 
 #cmakedefine FIONREAD_IN_SYS_IOCTL 1
 #cmakedefine GWINSZ_IN_SYS_IOCTL 1
