$NetBSD: patch-config.h.cmake,v 1.1 2025/09/06 18:27:52 riastradh Exp $

Add NetBSD support.

--- config.h.cmake.orig	2024-07-05 05:53:08.000000000 +0000
+++ config.h.cmake
@@ -20,6 +20,7 @@
 #cmakedefine HAVE_GRP_H 1
 #cmakedefine HAVE_NSS_H 1
 #cmakedefine HAVE_NSS_COMMON_H 1
+#cmakedefine HAVE_NSSWITCH_H 1
 #cmakedefine HAVE_GNU_LIB_NAMES_H 1
 
 /*************************** FUNCTIONS ***************************/
