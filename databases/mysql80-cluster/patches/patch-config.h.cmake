$NetBSD: patch-config.h.cmake,v 1.1 2024/08/05 01:23:59 jnemeth Exp $

--- config.h.cmake.orig	2022-03-23 13:49:36.000000000 +0000
+++ config.h.cmake
@@ -39,6 +39,7 @@
 /* Header files */
 #cmakedefine HAVE_ALLOCA_H 1
 #cmakedefine HAVE_ARPA_INET_H 1
+#cmakedefine HAVE_BSTRING_H 1
 #cmakedefine HAVE_DLFCN_H 1
 #cmakedefine HAVE_EXECINFO_H 1
 #cmakedefine HAVE_FPU_CONTROL_H 1
@@ -79,6 +80,7 @@
 #cmakedefine HAVE_FDATASYNC 1
 #cmakedefine HAVE_DECL_FDATASYNC 1
 #cmakedefine HAVE_FEDISABLEEXCEPT 1
+#cmakedefine HAVE_FFSLL 1
 #cmakedefine HAVE_FSYNC 1
 #cmakedefine HAVE_GETHRTIME 1
 #cmakedefine HAVE_GETPASS 1
