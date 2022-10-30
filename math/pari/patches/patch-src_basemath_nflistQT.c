$NetBSD: patch-src_basemath_nflistQT.c,v 1.1 2022/10/30 10:00:15 nros Exp $

* Don't conflict with NetBSDs strtoi function

--- src/basemath/nflistQT.c.orig	2022-09-16 17:16:27.000000000 +0000
+++ src/basemath/nflistQT.c
@@ -19,8 +19,8 @@ strtoint(char *s)
 {
   long neg = (*s == '-');
   GEN n;
-  if (!neg) return strtoi(s);
-  n = strtoi(s+1); togglesign(n); return n;
+  if (!neg) return pari_strtoi(s);
+  n = pari_strtoi(s+1); togglesign(n); return n;
 }
 /* export ? */
 static GEN
