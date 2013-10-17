$NetBSD: patch-src_kn10def.h,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/kn10def.h.orig	2006-06-15 17:30:59.000000000 +0000
+++ src/kn10def.h
@@ -235,7 +235,7 @@ typedef int     pcinc_t;	/* Type of all 
 #if KLH10_EXTADR
 # define PC_ADDXCT(x) { register pcinc_t i__ = (x); if (i__) PC_ADD(i__); }
 #else
-# define PC_ADDXCT(x) (cpu.mr_PC += (x))	/* For now; fix up later? */
+# define PC_ADDXCT(x) { volatile pcinc_t i__ = (x); cpu.mr_PC += i__; }
 #endif
 
 /* Macros for putting PC into a word.
