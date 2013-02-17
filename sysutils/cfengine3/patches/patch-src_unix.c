$NetBSD: patch-src_unix.c,v 1.1 2013/02/17 16:15:42 fhajny Exp $

Ignore HAVE_STRUCT_SOCKADDR_SA_LEN on NetBSD.

--- src/unix.c.orig	2013-01-11 12:54:39.000000000 +0000
+++ src/unix.c	2013-02-16 11:10:41.263683099 +0000
@@ -49,7 +49,7 @@
 
 #ifndef MINGW
 
-# ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
+# if defined(HAVE_STRUCT_SOCKADDR_SA_LEN) && !defined(__NetBSD__)
 #  ifdef _SIZEOF_ADDR_IFREQ
 #   define SIZEOF_IFREQ(x) _SIZEOF_ADDR_IFREQ(x)
 #  else
