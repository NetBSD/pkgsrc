$NetBSD: patch-src_resolver.c,v 1.2 2015/03/01 15:18:43 wiz Exp $

Use getaddrinfo(3) even if AI_ADDRCONFIG is missing.
http://bugs.musicpd.org/view.php?id=4326

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
