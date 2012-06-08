$NetBSD: patch-memcached_dtrace.d,v 1.1 2012/06/08 11:48:04 fhajny Exp $

Add missing DTrace probe.
http://code.google.com/p/memcached/issues/detail?id=254

--- memcached_dtrace.d.orig	2010-09-22 14:46:24.000000000 +0000
+++ memcached_dtrace.d
@@ -251,6 +251,17 @@ provider memcached {
    probe command__append(int connid, const char *key, int keylen, int size, int64_t casid);
 
    /**
+    * Fired for an touch-command.
+    * @param connid connection id
+    * @param key requested key
+    * @param keylen length of the key
+    * @param size the new size of the key's data (or signed int -1 if
+    *             not found)
+    * @param casid the casid for the item
+    */
+   probe command__touch(int connid, const char *key, int keylen, int size, int64_t casid);
+
+   /**
     * Fired for a cas-command.
     * @param connid connection id
     * @param key requested key
