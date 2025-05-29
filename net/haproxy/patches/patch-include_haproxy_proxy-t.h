$NetBSD: patch-include_haproxy_proxy-t.h,v 1.3 2025/05/29 20:36:26 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/proxy-t.h.orig	2025-05-28 14:35:14.000000000 +0000
+++ include/haproxy/proxy-t.h
@@ -302,7 +302,7 @@ struct error_snapshot {
 
 /* Each proxy will have one occurrence of this structure per thread group */
 struct proxy_per_tgroup {
-	struct queue queue;
+	struct haqueue queue;
 	struct lbprm_per_tgrp lbprm;
 } THREAD_ALIGNED(64);
 
