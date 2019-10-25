$NetBSD: patch-lib_ofx__preproc.cpp,v 1.3 2019/10/25 09:23:37 kamil Exp $

Fix build on NetBSD where iconv has a different prototype.
http://sourceforge.net/p/libofx/bugs/44/

--- lib/ofx_preproc.cpp.orig	2014-09-12 19:26:30.000000000 +0000
+++ lib/ofx_preproc.cpp
@@ -34,6 +34,15 @@
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
 #ifdef OS_WIN32
 # define DIRSEP "\\"
 #else
@@ -310,7 +319,7 @@ int ofx_proc_file(LibofxContextPtr ctx, 
             size_t outbytesleft = inbytesleft * 2 - 1;
             iconv_buffer = (char*) malloc (inbytesleft * 2);
             memset(iconv_buffer, 0, inbytesleft * 2);
-#if defined(OS_WIN32) || defined(__sun)
+#if defined(OS_WIN32) || defined(__sun) || (defined(__NetBSD__) && !NETBSD_POSIX_ICONV)
             const char * inchar = (const char *)s_buffer.c_str();
 #else
             char * inchar = (char *)s_buffer.c_str();
@@ -655,5 +664,3 @@ std::string find_dtd(LibofxContextPtr ct
   message_out(ERROR, "find_dtd():Unable to find the DTD named " + dtd_filename);
   return "";
 }
-
-
