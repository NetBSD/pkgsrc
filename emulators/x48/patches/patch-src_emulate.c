$NetBSD: patch-src_emulate.c,v 1.2 2013/07/08 08:37:10 he Exp $

Add static to an inline function.

--- src/emulate.c.orig	2013-01-16 14:12:03.000000000 +0000
+++ src/emulate.c
@@ -692,7 +692,7 @@ decode_group_1()
   }
 }
 
-inline int
+static inline int
 #ifdef __FunctionProto__
 decode_8_thru_f(int op1)
 #else
