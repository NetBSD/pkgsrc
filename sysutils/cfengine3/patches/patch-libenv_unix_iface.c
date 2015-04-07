$NetBSD: patch-libenv_unix_iface.c,v 1.1 2015/04/07 08:43:35 fhajny Exp $

Ignore HAVE_STRUCT_SOCKADDR_SA_LEN on NetBSD, behavior different.

--- libenv/unix_iface.c.orig	2015-03-12 20:21:31.000000000 +0000
+++ libenv/unix_iface.c
@@ -52,7 +52,7 @@
 
 #ifndef __MINGW32__
 
-# ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
+# if defined(HAVE_STRUCT_SOCKADDR_SA_LEN) && !defined(__NetBSD__)
 #  ifdef _SIZEOF_ADDR_IFREQ
 #   define SIZEOF_IFREQ(x) _SIZEOF_ADDR_IFREQ(x)
 #  else
