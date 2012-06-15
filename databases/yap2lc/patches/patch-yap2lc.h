$NetBSD: patch-yap2lc.h,v 1.1 2012/06/15 18:47:45 joerg Exp $

--- yap2lc.h.orig	2012-06-15 14:41:48.000000000 +0000
+++ yap2lc.h
@@ -161,10 +161,10 @@ sanity_check(struct passwd *pwd);
 #endif
 
 #if HAVE_SHADOW_H == 1
-inline void
+void
 fillvar(u_long pos, struct passwd *pwd, struct spwd *shadow);
 #else
-inline void
+void
 fillvar(u_long pos, struct passwd *pwd);
 #endif
 
