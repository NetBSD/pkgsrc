$NetBSD: patch-curvecp_curvecpclient.c,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Part of Debian 0004-fix-segfault.patch:
Fix segfault.

--- curvecp/curvecpclient.c.orig	2011-02-21 01:49:34.000000000 +0000
+++ curvecp/curvecpclient.c
@@ -96,6 +96,7 @@ int multiipparse(unsigned char *y,const 
   long long j;
   long long k;
   long long d;
+  if (!x) return 0;
   for (j = 0;j < 4 * NUMIP;++j) y[j] = 0;
   ynum = 0;
   while (ynum < 1000) {
