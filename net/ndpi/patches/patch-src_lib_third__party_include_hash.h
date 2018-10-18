$NetBSD: patch-src_lib_third__party_include_hash.h,v 1.1 2018/10/18 16:24:29 adam Exp $

Fix build (https://github.com/ntop/nDPI/issues/600).

--- src/lib/third_party/include/hash.h.orig	2018-10-08 10:12:59.000000000 +0000
+++ src/lib/third_party/include/hash.h
@@ -25,5 +25,6 @@ extern int ht_hash( hashtable_t *hashtab
 extern entry_t *ht_newpair( char *key, u_int16_t value );
 extern void ht_set( hashtable_t *hashtable, char *key, u_int16_t value );
 extern u_int16_t ht_get( hashtable_t *hashtable, char *key );
+extern void ht_free( hashtable_t *hashtable );
 
 #endif /* _HASH_H_ */
