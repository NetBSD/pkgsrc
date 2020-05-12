$NetBSD: patch-lib_ofx__preproc.cpp,v 1.4 2020/05/12 06:03:48 adam Exp $

Fix build on NetBSD where iconv has a different prototype.
http://sourceforge.net/p/libofx/bugs/44/

--- lib/ofx_preproc.cpp.orig	2020-05-10 08:10:38.019501839 +0000
+++ lib/ofx_preproc.cpp
@@ -35,6 +35,15 @@
 #include <iconv.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 #ifdef __WIN32__
 # define DIRSEP "\\"
 #else
@@ -307,7 +316,7 @@ int ofx_proc_file(LibofxContextPtr ctx, 
             size_t outbytesleft = inbytesleft * 2 - 1;
             char * iconv_buffer = (char*) malloc (inbytesleft * 2);
             memset(iconv_buffer, 0, inbytesleft * 2);
-#if defined(__sun) || defined(__NetBSD__)
+#if defined(__sun) || (defined(__NetBSD__) && !NETBSD_POSIX_ICONV)
             const char * inchar = (const char *)s_buffer.c_str();
 #else
             char * inchar = (char *)s_buffer.c_str();
