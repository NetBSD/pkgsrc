$NetBSD: patch-src_libmpdclient.c,v 1.1 2012/03/04 20:10:47 jakllsch Exp $
Use getaddrinfo(3) even if AI_ADDRCONFIG is missing.

--- src/libmpdclient.c.orig	2010-03-22 03:18:23.000000000 +0000
+++ src/libmpdclient.c
@@ -64,6 +64,9 @@
 #define COMMAND_LIST_OK 2
 
 #ifndef MPD_NO_GAI
+#  ifndef AI_ADDRCONFIG
+#    define AI_ADDRCONFIG 0
+#  endif
 #  ifdef AI_ADDRCONFIG
 #    define MPD_HAVE_GAI
 #  endif
