$NetBSD: patch-config.h.cmake,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* bstring.h is needed for bzero on some platforms.
* check for ffsll and provide a portable version for sytems that
  don't have it.

--- config.h.cmake.orig	2021-03-22 08:44:50.000000000 +0000
+++ config.h.cmake
@@ -40,6 +40,7 @@
 /* Header files */
 #cmakedefine HAVE_ALLOCA_H 1
 #cmakedefine HAVE_ARPA_INET_H 1
+#cmakedefine HAVE_BSTRING_H 1
 #cmakedefine HAVE_DLFCN_H 1
 #cmakedefine HAVE_EXECINFO_H 1
 #cmakedefine HAVE_FPU_CONTROL_H 1
@@ -80,6 +81,7 @@
 #cmakedefine HAVE_FDATASYNC 1
 #cmakedefine HAVE_DECL_FDATASYNC 1
 #cmakedefine HAVE_FEDISABLEEXCEPT 1
+#cmakedefine HAVE_FFSLL 1
 #cmakedefine HAVE_FSYNC 1
 #cmakedefine HAVE_GETHRTIME 1
 #cmakedefine HAVE_GETPASS 1
