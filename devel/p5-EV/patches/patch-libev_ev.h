$NetBSD: patch-libev_ev.h,v 1.2 2013/09/02 12:23:43 obache Exp $

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
 
