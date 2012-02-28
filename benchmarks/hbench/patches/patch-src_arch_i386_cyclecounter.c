$NetBSD: patch-src_arch_i386_cyclecounter.c,v 1.1 2012/02/28 15:49:56 hans Exp $

--- src/arch/i386/cyclecounter.c.orig	2003-02-28 18:19:53.000000000 +0100
+++ src/arch/i386/cyclecounter.c	2012-02-28 16:40:39.132704974 +0100
@@ -62,8 +62,8 @@
  * instruction for the TCP bandwidth test.
  */
 
-typedef u_int32_t clk_t;	/* time stamps are 64 bit on the Pentium Pro */
-typedef u_int64_t internal_clk_t;
+typedef uint32_t clk_t;	/* time stamps are 64 bit on the Pentium Pro */
+typedef uint64_t internal_clk_t;
 #define CLKTFMT		"%d"
 #define CLKTSTR(x) 	((int)strtol(x, NULL, 10))
 
