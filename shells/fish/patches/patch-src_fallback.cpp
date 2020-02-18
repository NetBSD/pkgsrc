$NetBSD: patch-src_fallback.cpp,v 1.3 2020/02/18 22:00:49 maya Exp $

constify, for clang

--- src/fallback.cpp.orig	2020-02-12 14:04:07.000000000 +0000
+++ src/fallback.cpp
@@ -47,8 +47,8 @@
 #if defined(TPARM_SOLARIS_KLUDGE)
 #undef tparm
 
-char *tparm_solaris_kludge(char *str, long p1, long p2, long p3, long p4, long p5, long p6, long p7,
-                           long p8, long p9) {
+char *tparm_solaris_kludge(const char *str, long p1, long p2, long p3, long p4,
+                           long p5, long p6, long p7, long p8, long p9) {
     return tparm(str, p1, p2, p3, p4, p5, p6, p7, p8, p9);
 }
 
