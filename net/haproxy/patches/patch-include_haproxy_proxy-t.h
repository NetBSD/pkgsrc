$NetBSD: patch-include_haproxy_proxy-t.h,v 1.6 2026/06/05 08:14:34 adam Exp $

Avoid 'struct queue' conflict.

--- include/haproxy/proxy-t.h.orig	2026-06-03 13:01:51.000000000 +0000
+++ include/haproxy/proxy-t.h
@@ -307,7 +307,7 @@ struct error_snapshot {
 
 /* Each proxy will have one occurrence of this structure per thread group */
 struct proxy_per_tgroup {
-	struct queue queue;
+	struct haqueue queue;
 	struct lbprm_per_tgrp lbprm;
 	char *extra_counters_fe_storage;        /* storage for extra_counters_fe */
 	char *extra_counters_be_storage;        /* storage for extra_counters_be */
