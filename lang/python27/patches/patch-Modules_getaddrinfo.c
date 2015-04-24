$NetBSD: patch-Modules_getaddrinfo.c,v 1.2 2015/04/24 03:01:36 rodent Exp $

--- Modules/getaddrinfo.c.orig	2014-12-10 15:59:55.000000000 +0000
+++ Modules/getaddrinfo.c
@@ -66,6 +66,15 @@
 #define YES 1
 #define NO  0
 
+/* SCO OpenServer 5.0.7/3.2's sys/reg.h defines ERR. */
+#if defined(ERR)
+#undef ERR
+#endif
+
+# if defined(_SCO_DS)
+typedef int socklen_t;
+#endif
+
 #ifdef FAITH
 static int translate = NO;
 static struct in6_addr faith_prefix = IN6ADDR_GAI_ANY_INIT;
