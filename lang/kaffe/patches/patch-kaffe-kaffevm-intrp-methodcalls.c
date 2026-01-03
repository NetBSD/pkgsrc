$NetBSD: patch-kaffe-kaffevm-intrp-methodcalls.c,v 1.1 2026/01/03 03:57:09 dholland Exp $

Hack to silence a gcc14 build error. Not at all clear if the code is
correct; the hack just restores the status quo.

--- kaffe/kaffevm/intrp/methodcalls.c~	2006-03-04 17:51:04.000000000 +0000
+++ kaffe/kaffevm/intrp/methodcalls.c
@@ -128,7 +128,14 @@ engine_callMethod (callMethodInfo *call)
 			if (func == NULL) {
 				throwError(&einfo);
 			}
-			setMethodCodeStart(meth, func);
+			/*
+			 * XXX: func is the wrong pointer type, and
+			 * this started failing with gcc14. Laundering
+			 * through (void *) makes it compile on the
+			 * assumption that whatever it's doing was
+			 * intended... but it may not have been.
+			 */
+			setMethodCodeStart(meth, (void *)func);
 			meth->accflags |= ACC_TRANSLATED;
 		}
 
