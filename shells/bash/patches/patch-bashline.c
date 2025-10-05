$NetBSD: patch-bashline.c,v 1.4 2025/10/05 11:18:27 js Exp $

--- bashline.c.orig	2025-06-25 19:53:44.000000000 +0000
+++ bashline.c
@@ -4142,7 +4142,7 @@ vi_advance_point (void)
 	}
     }
 #else
-    rl_point++:
+    rl_point++;
 #endif
   return point;
 }
