$NetBSD: patch-src_core_config-kmountpoint.h.cmake,v 1.1 2016/05/26 08:29:05 markd Exp $

--- src/core/config-kmountpoint.h.cmake.orig	2016-04-03 20:55:42.000000000 +0000
+++ src/core/config-kmountpoint.h.cmake
@@ -1,4 +1,5 @@
 #cmakedefine01 HAVE_GETMNTINFO
+#cmakedefine01 GETMNTINFO_USES_STATVFS
 #cmakedefine01 HAVE_SETMNTENT
 #cmakedefine01 HAVE_MNTENT_H
 #cmakedefine01 HAVE_SYS_MNTTAB_H
