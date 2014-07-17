$NetBSD: patch-Modules_socketmodule.c,v 1.4 2014/07/17 15:26:49 ryoon Exp $

--- Modules/socketmodule.c.orig	2014-06-30 02:05:43.000000000 +0000
+++ Modules/socketmodule.c
@@ -244,7 +244,7 @@ shutdown(how) -- shut down traffic in on
 /* Irix 6.5 fails to define this variable at all. This is needed
    for both GCC and SGI's compiler. I'd say that the SGI headers
    are just busted. Same thing for Solaris. */
-#if (defined(__sgi) || defined(sun)) && !defined(INET_ADDRSTRLEN)
+#if (defined(__sgi) || defined(sun) || defined(_SCO_DS)) && !defined(INET_ADDRSTRLEN)
 #define INET_ADDRSTRLEN 16
 #endif
 
