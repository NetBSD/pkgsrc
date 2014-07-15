$NetBSD: patch-src_fccharset.c,v 1.1 2014/07/15 14:48:34 ryoon Exp $

--- src/fccharset.c.orig	2014-01-20 08:14:20.000000000 +0000
+++ src/fccharset.c
@@ -569,7 +569,7 @@ FcCharSetHasChar (const FcCharSet *fcs, 
 static FcChar32
 FcCharSetPopCount (FcChar32 c1)
 {
-#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
+#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)) && !defined(_SCO_DS)
     return __builtin_popcount (c1);
 #else
     /* hackmem 169 */
