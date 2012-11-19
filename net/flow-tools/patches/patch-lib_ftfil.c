$NetBSD: patch-lib_ftfil.c,v 1.1 2012/11/19 02:58:12 joerg Exp $

--- lib/ftfil.c.orig	2012-11-19 00:45:30.000000000 +0000
+++ lib/ftfil.c
@@ -76,6 +76,8 @@
     rn_init_called = 1;\
   }\
 
+#define inline
+
 extern int max_keylen;
 extern u_int32 mask_lookup[];
 static int rn_init_called;
