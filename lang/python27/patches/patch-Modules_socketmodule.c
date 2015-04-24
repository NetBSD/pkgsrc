$NetBSD: patch-Modules_socketmodule.c,v 1.5 2015/04/24 03:01:36 rodent Exp $

--- Modules/socketmodule.c.orig	2014-12-10 15:59:55.000000000 +0000
+++ Modules/socketmodule.c
@@ -248,7 +248,7 @@ shutdown(how) -- shut down traffic in on
 /* Irix 6.5 fails to define this variable at all. This is needed
    for both GCC and SGI's compiler. I'd say that the SGI headers
    are just busted. Same thing for Solaris. */
-#if (defined(__sgi) || defined(sun)) && !defined(INET_ADDRSTRLEN)
+#if (defined(__sgi) || defined(sun) || defined(_SCO_DS)) && !defined(INET_ADDRSTRLEN)
 #define INET_ADDRSTRLEN 16
 #endif
 
