$NetBSD: patch-libev_ev.h,v 1.4 2019/10/17 13:59:08 mef Exp $

Don't define a variable as both static and extern.

--- libev/ev.h.orig	2019-06-26 14:15:30.000000000 +0900
+++ libev/ev.h	2019-10-17 22:55:20.971868889 +0900
@@ -565,8 +565,6 @@ EV_API_DECL struct ev_loop *ev_default_l
 EV_INLINE struct ev_loop *
 ev_default_loop_uc_ (void) EV_NOEXCEPT
 {
-  extern struct ev_loop *ev_default_loop_ptr;
-
   return ev_default_loop_ptr;
 }
 
