$NetBSD: patch-regex_regex2.h,v 1.1 2011/02/12 02:52:34 obache Exp $

* PR#42832: Fixes for 64bit envronment

--- regex/regex2.h.orig	2011-02-12 02:44:39.000000000 +0000
+++ regex/regex2.h
@@ -80,8 +80,8 @@ typedef int sopno;
 #define	OPRMASK	0xf8000000
 #define	OPDMASK	0x07ffffff
 #define	OPSHIFT	((unsigned)27)
-#define	OP(n)	((n)&OPRMASK)
-#define	OPND(n)	((n)&OPDMASK)
+#define	OP(n)	((unsigned)((n)&OPRMASK))
+#define	OPND(n)	((unsigned)((n)&OPDMASK))
 #define	SOP(op, opnd)	((op)|(opnd))
 /* operators			   meaning	operand			*/
 /*						(back, fwd are offsets)	*/
