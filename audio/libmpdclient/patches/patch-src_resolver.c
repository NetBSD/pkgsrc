$NetBSD: patch-src_resolver.c,v 1.1 2012/03/04 20:10:47 jakllsch Exp $
Use getaddrinfo(3) even if AI_ADDRCONFIG is missing.

--- src/resolver.c.orig	2011-10-24 02:43:05.000000000 +0000
+++ src/resolver.c
@@ -47,6 +47,9 @@
 #endif
 
 #if defined(ENABLE_TCP) && !defined(MPD_NO_GAI)
+#  ifndef AI_ADDRCONFIG
+#    define AI_ADDRCONFIG 0
+#  endif
 #  ifdef AI_ADDRCONFIG
 #    define MPD_HAVE_GAI
 #  endif
