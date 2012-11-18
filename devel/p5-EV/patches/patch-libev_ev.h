$NetBSD: patch-libev_ev.h,v 1.1 2012/11/18 01:54:02 joerg Exp $

--- libev/ev.h.orig	2012-11-17 12:01:52.000000000 +0000
+++ libev/ev.h
@@ -549,8 +549,6 @@ EV_API_DECL struct ev_loop *ev_default_l
 EV_INLINE struct ev_loop *
 ev_default_loop_uc_ (void)
 {
-  extern struct ev_loop *ev_default_loop_ptr;
-
   return ev_default_loop_ptr;
 }
 
