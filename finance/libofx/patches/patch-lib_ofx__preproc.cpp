$NetBSD: patch-lib_ofx__preproc.cpp,v 1.2 2014/12/30 13:20:29 wiz Exp $

Fix build on NetBSD where iconv has a different prototype.
http://sourceforge.net/p/libofx/bugs/44/

--- lib/ofx_preproc.cpp.orig	2014-09-12 19:26:30.000000000 +0000
+++ lib/ofx_preproc.cpp
@@ -310,7 +310,7 @@ int ofx_proc_file(LibofxContextPtr ctx, 
             size_t outbytesleft = inbytesleft * 2 - 1;
             iconv_buffer = (char*) malloc (inbytesleft * 2);
             memset(iconv_buffer, 0, inbytesleft * 2);
-#if defined(OS_WIN32) || defined(__sun)
+#if defined(OS_WIN32) || defined(__sun) || defined(__NetBSD__)
             const char * inchar = (const char *)s_buffer.c_str();
 #else
             char * inchar = (char *)s_buffer.c_str();
