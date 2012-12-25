$NetBSD: patch-src_ushare.h,v 1.1 2012/12/25 21:05:50 joerg Exp $

--- src/ushare.h.orig	2012-12-25 19:29:41.000000000 +0000
+++ src/ushare.h
@@ -127,6 +127,6 @@ struct action_event_t {
   struct service_t *service;
 };
 
-inline void display_headers (void);
+void display_headers (void);
 
 #endif /* _USHARE_H_ */
