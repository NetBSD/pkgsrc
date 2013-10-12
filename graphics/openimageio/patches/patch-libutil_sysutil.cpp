$NetBSD: patch-libutil_sysutil.cpp,v 1.2 2013/10/12 22:13:44 ryoon Exp $

* Treat NetBSD like Linux (I am not sure)

--- libutil/sysutil.cpp.orig	2013-09-30 17:25:21.000000000 +0000
+++ libutil/sysutil.cpp
@@ -39,7 +39,7 @@
 # include <sys/ioctl.h>
 #endif
 
-#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined (__NetBSD__)
 # include <sys/types.h>
 # include <sys/resource.h>
 # include <sys/sysctl.h>
@@ -150,7 +150,7 @@ Sysutil::this_program_path ()
     char filename[10240];
     filename[0] = 0;
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
     unsigned int size = sizeof(filename);
     int r = readlink ("/proc/self/exe", filename, size);
     ASSERT(r < int(size)); // user won't get the right answer if the filename is too long to store
