$NetBSD: patch-src_fccharset.c,v 1.4 2023/01/20 13:10:09 wiz Exp $

- Fix build on SCO OpenServer 5.0.7/3.2.

--- src/fccharset.c.orig	2018-06-05 10:36:38.000000000 +0000
+++ src/fccharset.c
@@ -600,7 +600,7 @@ FcCharSetHasChar (const FcCharSet *fcs, 
 static FcChar32
 FcCharSetPopCount (FcChar32 c1)
 {
-#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
+#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)) && !defined(_SCO_DS)
     return __builtin_popcount (c1);
 #else
     /* hackmem 169 */
