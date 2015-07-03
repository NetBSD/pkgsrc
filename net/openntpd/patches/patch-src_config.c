$NetBSD: patch-src_config.c,v 1.1 2015/07/03 12:31:12 wiz Exp $

Abort if configuration specifies tls constraints and ntpd not compiled with
tls support; accepted upstream.

--- src/config.c.orig	2015-03-25 01:18:56.000000000 +0000
+++ src/config.c
@@ -218,6 +218,9 @@ new_constraint(void)
 		fatal("new_constraint calloc");
 	p->id = ++constraint_maxid;
 
+#ifndef HAVE_LIBTLS
+	fatal("constraint configured without libtls support");
+#endif
 	return (p);
 }
 
