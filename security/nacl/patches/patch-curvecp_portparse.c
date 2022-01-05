$NetBSD: patch-curvecp_portparse.c,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Part of Debian 0004-fix-segfault.patch:
Fix segfault.

--- curvecp/portparse.c.orig	2011-02-21 01:49:34.000000000 +0000
+++ curvecp/portparse.c
@@ -4,6 +4,7 @@ int portparse(unsigned char *y,const cha
 {
   long long d = 0;
   long long j;
+  if (!x) return 0;
   for (j = 0;j < 5 && x[j] >= '0' && x[j] <= '9';++j)
     d = d * 10 + (x[j] - '0');
   if (j == 0) return 0;
