$NetBSD: patch-pdfium_third__party_libopenjpeg20_opj__malloc.h,v 1.2 2021/10/26 17:56:54 nros Exp $

* use posix memalign on BSD systems

--- pdfium/third_party/libopenjpeg20/opj_malloc.h.orig	2019-05-04 19:18:14.758209492 +0000
+++ pdfium/third_party/libopenjpeg20/opj_malloc.h
@@ -98,7 +98,7 @@ Allocate memory aligned to a 16 byte bou
 #else /* Not _WIN32 */
 	#if defined(__sun)
 		#define HAVE_MEMALIGN
-  #elif defined(__FreeBSD__)
+  #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(DragonFly)
     #define HAVE_POSIX_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__) && !defined(_AIX)
