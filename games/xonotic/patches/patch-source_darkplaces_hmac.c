$NetBSD: patch-source_darkplaces_hmac.c,v 1.1 2019/10/01 12:32:26 nia Exp $

Avoid conflicting with NetBSD libc.

--- source/darkplaces/hmac.c.orig	2017-04-01 13:26:56.000000000 +0000
+++ source/darkplaces/hmac.c
@@ -1,7 +1,7 @@
 #include "quakedef.h"
 #include "hmac.h"
 
-qboolean hmac(
+qboolean darkplaces_hmac(
 	hashfunc_t hfunc, int hlen, int hblock,
 	unsigned char *out,
 	const unsigned char *in, int n,
