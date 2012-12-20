$NetBSD: patch-main_event.c,v 1.1 2012/12/20 21:59:21 joerg Exp $

--- main/event.c.orig	2012-12-20 19:12:33.000000000 +0000
+++ main/event.c
@@ -16,7 +16,7 @@
 
 /* time for next event - update vdp_event - return when to call again */
 
-inline void event_nextevent(void)
+static inline void event_nextevent(void)
 {
   /* call this when it *is* time for the next event as dictated by vdp_event,
      so we switch on it and update vdp_event at the same time */
