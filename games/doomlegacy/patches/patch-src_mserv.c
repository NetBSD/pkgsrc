$NetBSD: patch-src_mserv.c,v 1.1 2020/06/15 10:32:52 micha Exp $

Use native inet_aton() on Solaris.

--- src/mserv.c.orig	2020-05-10 22:05:17.000000000 +0000
+++ src/mserv.c
@@ -210,7 +210,9 @@ struct Copy_CVarMS_t
 #define close closesocket
 #endif
 
-#if defined( WIN32) || defined( __OS2__) || defined( SOLARIS)
+// For pkgsrc: Use native inet_aton() on Solaris
+// Solaris has inet_aton() in libresolv since version 2.6 from 1997
+#if defined( WIN32) || defined( __OS2__) // || defined( SOLARIS)
 // it seems windows doesn't define that... maybe some other OS? OS/2
 static inline
 int inet_aton(const char *hostname,
