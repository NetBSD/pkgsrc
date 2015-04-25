$NetBSD: patch-squint_compile.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Avoid naming conflict with standard C.

--- squint/compile.c~	2000-02-11 17:04:43.000000000 +0000
+++ squint/compile.c
@@ -228,7 +228,7 @@ gen(Node *n, int retain)
 		case PRINT:
 			gen(n->l, 1);
 			printgen(n->l);
-			emit(Isprint);
+			emit(Isprint_);
 			if(!retain)
 				emit(Iprint);
 			return;
