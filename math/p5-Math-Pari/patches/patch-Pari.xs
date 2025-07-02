$NetBSD: patch-Pari.xs,v 1.1 2025/07/02 03:07:31 markd Exp $

define changevalue()

--- Pari.xs.orig	2025-05-10 01:21:46.000000000 +0000
+++ Pari.xs
@@ -641,6 +641,8 @@ changevalue(entree *ep, GEN val)
   y[-1] = x[-1]; /* save initial value */
   killbloc(x);   /* destroy intermediate one */
 }
+#else
+void changevalue(entree *ep, GEN val);
 #endif
 
 static GEN
