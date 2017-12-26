$NetBSD: patch-Source_LibOpenJPEG_opj__malloc.h,v 1.2 2017/12/26 11:55:01 he Exp $

Add a case for NetBSD.

--- Source/LibOpenJPEG/opj_malloc.h.orig	2015-02-12 12:40:33.000000000 -0800
+++ Source/LibOpenJPEG/opj_malloc.h	2015-02-12 12:42:08.000000000 -0800
@@ -95,6 +95,8 @@ Allocate memory aligned to a 16 byte bou
 		#define HAVE_MEMALIGN
   #elif defined(__FreeBSD__)
     #define HAVE_POSIX_MEMALIGN
+  #elif defined(__NetBSD__)
+    #define HAVE_POSIX_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__) && !defined(_AIX)
 		#define HAVE_MEMALIGN
