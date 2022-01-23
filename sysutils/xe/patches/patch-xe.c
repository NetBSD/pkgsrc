$NetBSD: patch-xe.c,v 1.1 2022/01/23 21:37:07 wiz Exp $

Avoid conflict with NetBSD's shquote.

--- xe.c.orig	2017-11-05 20:03:12.000000000 +0000
+++ xe.c
@@ -130,7 +130,7 @@ my_child:
 }
 
 static void
-shquote(const char *s)
+xe_shquote(const char *s)
 {
 	if (*s &&
 	    !strpbrk(s, "\001\002\003\004\005\006\007\010"
@@ -159,7 +159,7 @@ trace()
 	for (i = 0; i < argslen; i++) {
 		if (i > 0)
 			fprintf(traceout, " ");
-		shquote(args[i]);
+		xe_shquote(args[i]);
 	}
 	fprintf(traceout, "\n");
 	fflush(traceout);
