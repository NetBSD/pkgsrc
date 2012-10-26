$NetBSD: patch-include_xracer-craft.h,v 1.1 2012/10/26 20:22:12 joerg Exp $

--- include/xracer-craft.h.orig	2012-10-26 13:35:24.000000000 +0000
+++ include/xracer-craft.h
@@ -68,9 +68,7 @@ extern const struct xrCraft *xrCraftGetD
 extern const struct xrCraft *xrCraftGetNext (const struct xrCraft *);
 
 /* Call display function for craft. */
-extern void xrCraftDisplay (const struct xrCraft *craft);
-
-extern inline void
+static inline void
 xrCraftDisplay (const struct xrCraft *craft)
 {
   craft->display ();
