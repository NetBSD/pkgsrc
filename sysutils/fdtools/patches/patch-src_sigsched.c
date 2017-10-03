$NetBSD: patch-src_sigsched.c,v 1.1 2017/10/03 00:43:22 schmonz Exp $

Provide a default definition, needed on at least OS X.

--- src/sigsched.c.orig	2015-03-16 03:55:56.000000000 +0000
+++ src/sigsched.c
@@ -36,11 +36,9 @@ XXX: how well do we clean up upon ss_exe
 #define sigc_block(x) (sigblock(*(x)))
 */
 
-/*
-//#ifndef NSIG
-//#define NSIG 64 / * it's not as if any sane system has more than 32 * /
-//#endif
-*/
+#ifndef NSIG
+#define NSIG 64 /* it's not as if any sane system has more than 32 */
+#endif
 
 #define NUMSIGS NSIG
 
