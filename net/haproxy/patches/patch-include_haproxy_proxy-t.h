$NetBSD: patch-include_haproxy_proxy-t.h,v 1.5 2025/12/02 12:55:24 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/proxy-t.h.orig	2025-11-26 14:55:57.000000000 +0000
+++ include/haproxy/proxy-t.h
@@ -302,7 +302,7 @@ struct error_snapshot {
 
 /* Each proxy will have one occurrence of this structure per thread group */
 struct proxy_per_tgroup {
-	struct queue queue;
+	struct haqueue queue;
 	struct lbprm_per_tgrp lbprm;
 } THREAD_ALIGNED(64);
 
