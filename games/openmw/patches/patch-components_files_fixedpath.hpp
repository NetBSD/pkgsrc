$NetBSD: patch-components_files_fixedpath.hpp,v 1.1 2019/08/09 16:26:09 nia Exp $

Support NetBSD.

--- components/files/fixedpath.hpp.orig	2017-11-15 17:20:40.000000000 +0000
+++ components/files/fixedpath.hpp
@@ -4,7 +4,7 @@
 #include <string>
 #include <boost/filesystem.hpp>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #ifndef ANDROID
     #include <components/files/linuxpath.hpp>
     namespace Files { typedef LinuxPath TargetPathType; }
