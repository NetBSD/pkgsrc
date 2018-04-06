$NetBSD: patch-xcftools.h,v 1.1 2018/04/06 03:44:19 maya Exp $

Re-order so we try to include arpa/inet.h first (available
in POSIX issue 6). The configure script for this 3rd party
tool doesn't exist.

--- plugins/impex/xcf/3rdparty/xcftools/xcftools.h.orig	2018-03-20 07:49:57.000000000 +0000
+++ plugins/impex/xcf/3rdparty/xcftools/xcftools.h
@@ -55,10 +55,10 @@ typedef signed long int   int32_t ;
 # define __ATTRIBUTE__(x)
 #endif
 
-#if HAVE_NETINET_IN_H
-# include <netinet/in.h>
-#elif HAVE_ARPA_INET_H
+#if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
 # include <arpa/inet.h>
+#elif HAVE_NETINET_IN_H
+# include <netinet/in.h>
 #elif WORDS_BIGENDIAN
 # define ntohl(x) (x)
 #else
