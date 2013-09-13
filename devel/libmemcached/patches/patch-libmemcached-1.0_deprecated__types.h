$NetBSD: patch-libmemcached-1.0_deprecated__types.h,v 1.2 2013/09/13 07:59:01 fhajny Exp $

Add type to overcome a breaking API change.
https://bugs.launchpad.net/libmemcached/+bug/1190240
--- libmemcached-1.0/deprecated_types.h.orig	2013-04-03 04:22:00.000000000 +0000
+++ libmemcached-1.0/deprecated_types.h
@@ -57,4 +57,5 @@ typedef memcached_server_fn memcached_se
 typedef memcached_trigger_key_fn memcached_trigger_key;
 typedef memcached_trigger_delete_key_fn memcached_trigger_delete_key;
 typedef memcached_dump_fn memcached_dump_func;
+typedef memcached_instance_st *memcached_server_instance_st;
 
