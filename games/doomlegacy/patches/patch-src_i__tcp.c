$NetBSD: patch-src_i__tcp.c,v 1.1 2019/06/17 13:53:22 micha Exp $

Disable IPX for NetBSD.

--- src/i_tcp.c.orig	2018-07-16 09:17:06.000000000 +0000
+++ src/i_tcp.c
@@ -169,6 +169,13 @@
 # endif
 #endif
 
+#ifdef NETBSD
+// NetBSD does not have IPX.
+# ifdef USE_IPX
+#   undef USE_IPX
+# endif
+#endif
+
 // Reported to be __OpenBSD__ , but it should be all caps and I am paranoid.
 #if defined( __OpenBSD__ ) || defined( __OPENBSD__ )
 // OpenBSD does not have IPX.
