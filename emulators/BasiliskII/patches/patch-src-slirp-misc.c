$NetBSD: patch-src-slirp-misc.c,v 1.1 2011/08/20 15:30:36 joerg Exp $

--- src/slirp/misc.c.orig	2011-08-20 13:13:50.000000000 +0000
+++ src/slirp/misc.c
@@ -106,7 +106,7 @@ struct quehead_32 {
 	u_int32_t qh_rlink;
 };
 
-inline void
+void
 insque_32(a, b)
 	void *a;
 	void *b;
@@ -120,7 +120,7 @@ insque_32(a, b)
 	= (u_int32_t)element;
 }
 
-inline void
+void
 remque_32(a)
 	void *a;
 {
