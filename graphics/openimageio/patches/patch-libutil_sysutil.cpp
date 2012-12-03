$NetBSD: patch-libutil_sysutil.cpp,v 1.1 2012/12/03 12:54:15 ryoon Exp $

* Treat NetBSD like Linux (I am not sure)

--- libutil/sysutil.cpp.orig	2012-11-16 23:02:42.000000000 +0000
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
     filename[0] = 0;
     unsigned int size = sizeof(filename);
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
     int r = readlink ("/proc/self/exe", filename, size);
     ASSERT(r < int(size)); // user won't get the right answer if the filename is too long to store
     if (r > 0) filename[r] = 0; // readlink does not fill in the 0 byte
