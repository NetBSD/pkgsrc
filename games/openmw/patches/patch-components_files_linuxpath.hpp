$NetBSD: patch-components_files_linuxpath.hpp,v 1.1 2019/08/09 16:26:09 nia Exp $

Support NetBSD.

--- components/files/linuxpath.hpp.orig	2017-11-15 17:20:40.000000000 +0000
+++ components/files/linuxpath.hpp
@@ -1,7 +1,7 @@
 #ifndef COMPONENTS_FILES_LINUXPATH_H
 #define COMPONENTS_FILES_LINUXPATH_H
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <boost/filesystem.hpp>
 
