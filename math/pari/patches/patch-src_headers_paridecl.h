$NetBSD: patch-src_headers_paridecl.h,v 1.2 2016/03/03 13:28:22 wiz Exp $

--- src/headers/paridecl.h.orig	2015-05-27 15:40:13.000000000 +0000
+++ src/headers/paridecl.h
@@ -1165,7 +1165,7 @@ GEN*    safelistel(GEN x, long l);
 GEN*    safegcoeff(GEN x, long a, long b);
 GEN     strntoGENstr(const char *s, long n0);
 GEN     strtoGENstr(const char *s);
-GEN     strtoi(const char *s);
+GEN     pari_strtoi(const char *s);
 GEN     strtor(const char *s, long prec);
 GEN     type0(GEN x);
 
