$NetBSD: patch-common_multibyte.c,v 1.1 2017/01/07 19:00:55 maya Exp $

Match an encoding in the case where more than one encoding works.

--- common/multibyte.c.orig	2017-01-07 18:20:05.869132249 +0000
+++ common/multibyte.c
@@ -1455,7 +1455,7 @@ multi_predict_region(sp, mstart, mend, e
 			return ename;
 
 		for (i = 0; i < maxfunc; i++) {
-			if (maybe == (1 << i))
+			if (maybe & (1 << i))
 				return dt->name[i];
 		}
 	}
