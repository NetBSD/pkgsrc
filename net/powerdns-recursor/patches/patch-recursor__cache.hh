$NetBSD: patch-recursor__cache.hh,v 1.1 2013/06/10 18:59:09 joerg Exp $

--- recursor_cache.hh.orig	2013-05-10 14:51:37.000000000 +0000
+++ recursor_cache.hh
@@ -64,7 +64,7 @@ private:
 
   struct CacheEntry
   {
-    CacheEntry(const tuple<string, uint16_t>& key, const vector<StoredRecord>& records, bool auth) : 
+    CacheEntry(const boost::tuple<string, uint16_t>& key, const vector<StoredRecord>& records, bool auth) : 
       d_qname(key.get<0>()), d_qtype(key.get<1>()), d_auth(auth), d_records(records)
     {}
 
