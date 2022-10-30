$NetBSD: patch-src_headers_paridecl.h,v 1.3 2022/10/30 10:00:15 nros Exp $

* Don't conflict with NetBSDs strtoi function

--- src/headers/paridecl.h.orig	2022-09-16 17:16:27.000000000 +0000
+++ src/headers/paridecl.h
@@ -2010,7 +2010,7 @@ GEN*    safegel(GEN x, long l);
 long*   safeel(GEN x, long l);
 GEN*    safelistel(GEN x, long l);
 GEN*    safegcoeff(GEN x, long a, long b);
-GEN     strtoi(const char *s);
+GEN     pari_strtoi(const char *s);
 GEN     strtor(const char *s, long prec);
 GEN     varhigher(const char *s, long v);
 GEN     varlower(const char *s, long v);
