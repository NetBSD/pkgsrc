$NetBSD: patch-ext_poppler_rbpoppler.c,v 1.1 2016/01/30 19:04:14 tsutsui Exp $

Pull upstream fix for poppler-0.39:
 https://github.com/ruby-gnome2/ruby-gnome2/commit/3dda85661515d71101f1028dc7d68d4e53de45b1

--- ext/poppler/rbpoppler.c.orig	2016-01-30 03:51:30.000000000 +0000
+++ ext/poppler/rbpoppler.c
@@ -56,7 +56,6 @@ Init_poppler(void)
                                 INT2FIX(POPPLER_MICRO_VERSION)));
 
     G_DEF_CLASS(POPPLER_TYPE_ERROR, "Error", RG_TARGET_NAMESPACE);
-    G_DEF_CLASS(POPPLER_TYPE_ORIENTATION, "Orientation", RG_TARGET_NAMESPACE);
 
     G_DEF_CLASS(POPPLER_TYPE_PAGE_TRANSITION_TYPE,
                 "PageTransitionType", RG_TARGET_NAMESPACE);
