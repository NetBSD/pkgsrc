$NetBSD: patch-libev_ev.h,v 1.3 2015/07/27 14:30:34 mef Exp $

Don't define a variable as both static and extern.

--- libev/ev.h.orig	2013-03-01 11:05:29.000000000 +0000
+++ libev/ev.h
@@ -557,8 +557,6 @@ EV_API_DECL struct ev_loop *ev_default_l
 EV_INLINE struct ev_loop *
 ev_default_loop_uc_ (void) EV_THROW
 {
-  extern struct ev_loop *ev_default_loop_ptr;
-
   return ev_default_loop_ptr;
 }
 
