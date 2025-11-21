$NetBSD: patch-include_haproxy_proxy-t.h,v 1.4 2025/11/21 09:25:15 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/proxy-t.h.orig	2025-11-21 06:44:17.000000000 +0000
+++ include/haproxy/proxy-t.h
@@ -302,7 +302,7 @@ struct error_snapshot {
 
 /* Each proxy will have one occurrence of this structure per thread group */
 struct proxy_per_tgroup {
-	struct queue queue;
+	struct haqueue queue;
 	struct lbprm_per_tgrp lbprm;
 };
 
