$NetBSD: patch-libf95.a-0.93_math_ff.c,v 1.2 2015/12/29 23:34:46 dholland Exp $

Fix assembler instructions.

--- libf95.a-0.93/math/ff.c.orig	2013-03-01 11:15:29.000000000 +0000
+++ libf95.a-0.93/math/ff.c
@@ -790,7 +790,7 @@ int exp;
 
     exp = *i - 1;
 
-    asm("fild %0\n"        /* i */
+    asm("filds %0\n"        /* i */
 	"fldt %1\n"        /* x : i */
 	"fxtract\n"        /* sig(x) : exp(x) : i */
 	"fstp %%st(1)\n"   /* sig(x) : i */
@@ -961,7 +961,7 @@ int exp;
 
     exp = *i;
 
-    asm("fild %0\n"
+    asm("filds %0\n"
 	"fldt %1\n"
 	"fscale\n"
 	"fstp %%st(1)\n" : : "m" (exp), "m" (*x));
@@ -1069,7 +1069,7 @@ int exp;
     case FF_REGULAR:
 	exp = MAN10_LEN - 1;
 
-	asm("fild %0\n"             /* p */
+	asm("filds %0\n"             /* p */
 	    "fldt %1\n"             /* x . p */
 	    "fxam\n"
 	    "fnstsw\n"
