$NetBSD: patch-tables_apr__hash.c,v 1.1.2.2 2012/02/12 01:36:32 sbd Exp $

http://svn.apache.org/viewvc/apr/apr/branches/1.4.x/tables/apr_hash.c
revision 1237547:
Randomise hashes by providing a seed (initial hash value).

--- tables/apr_hash.c.orig	2010-01-19 21:39:11.000000000 +0000
+++ tables/apr_hash.c
@@ -18,6 +18,7 @@
 
 #include "apr_general.h"
 #include "apr_pools.h"
+#include "apr_time.h"
 
 #include "apr_hash.h"
 
@@ -75,7 +76,7 @@ struct apr_hash_t {
     apr_pool_t          *pool;
     apr_hash_entry_t   **array;
     apr_hash_index_t     iterator;  /* For apr_hash_first(NULL, ...) */
-    unsigned int         count, max;
+    unsigned int         count, max, seed;
     apr_hashfunc_t       hash_func;
     apr_hash_entry_t    *free;  /* List of recycled entries */
 };
@@ -95,13 +96,18 @@ static apr_hash_entry_t **alloc_array(ap
 APR_DECLARE(apr_hash_t *) apr_hash_make(apr_pool_t *pool)
 {
     apr_hash_t *ht;
+    apr_time_t now = apr_time_now();
+
     ht = apr_palloc(pool, sizeof(apr_hash_t));
     ht->pool = pool;
     ht->free = NULL;
     ht->count = 0;
     ht->max = INITIAL_MAX;
+    ht->seed = (unsigned int)((now >> 32) ^ now ^ (apr_uintptr_t)pool ^
+                              (apr_uintptr_t)ht ^ (apr_uintptr_t)&now) - 1;
     ht->array = alloc_array(ht, ht->max);
-    ht->hash_func = apr_hashfunc_default;
+    ht->hash_func = NULL;
+
     return ht;
 }
 
@@ -178,10 +184,9 @@ static void expand_array(apr_hash_t *ht)
     ht->max = new_max;
 }
 
-APR_DECLARE_NONSTD(unsigned int) apr_hashfunc_default(const char *char_key,
-                                                      apr_ssize_t *klen)
+static unsigned int hashfunc_default(const char *char_key, apr_ssize_t *klen,
+                                     unsigned int hash)
 {
-    unsigned int hash = 0;
     const unsigned char *key = (const unsigned char *)char_key;
     const unsigned char *p;
     apr_ssize_t i;
@@ -223,7 +228,7 @@ APR_DECLARE_NONSTD(unsigned int) apr_has
      *
      *                  -- Ralf S. Engelschall <rse@engelschall.com>
      */
-     
+
     if (*klen == APR_HASH_KEY_STRING) {
         for (p = key; *p; p++) {
             hash = hash * 33 + *p;
@@ -239,6 +244,11 @@ APR_DECLARE_NONSTD(unsigned int) apr_has
     return hash;
 }
 
+APR_DECLARE_NONSTD(unsigned int) apr_hashfunc_default(const char *char_key,
+                                                      apr_ssize_t *klen)
+{
+    return hashfunc_default(char_key, klen, 0);
+}
 
 /*
  * This is where we keep the details of the hash function and control
@@ -257,7 +267,10 @@ static apr_hash_entry_t **find_entry(apr
     apr_hash_entry_t **hep, *he;
     unsigned int hash;
 
-    hash = ht->hash_func(key, &klen);
+    if (ht->hash_func)
+        hash = ht->hash_func(key, &klen);
+    else
+        hash = hashfunc_default(key, &klen, ht->seed);
 
     /* scan linked list */
     for (hep = &ht->array[hash & ht->max], he = *hep;
@@ -299,6 +312,7 @@ APR_DECLARE(apr_hash_t *) apr_hash_copy(
     ht->free = NULL;
     ht->count = orig->count;
     ht->max = orig->max;
+    ht->seed = orig->seed;
     ht->hash_func = orig->hash_func;
     ht->array = (apr_hash_entry_t **)((char *)ht + sizeof(apr_hash_t));
 
@@ -396,7 +410,7 @@ APR_DECLARE(apr_hash_t *) apr_hash_merge
     apr_hash_entry_t *new_vals = NULL;
     apr_hash_entry_t *iter;
     apr_hash_entry_t *ent;
-    unsigned int i,j,k;
+    unsigned int i, j, k, hash;
 
 #if APR_POOL_DEBUG
     /* we don't copy keys and values, so it's necessary that
@@ -424,6 +438,7 @@ APR_DECLARE(apr_hash_t *) apr_hash_merge
     if (base->count + overlay->count > res->max) {
         res->max = res->max * 2 + 1;
     }
+    res->seed = base->seed;
     res->array = alloc_array(res, res->max);
     if (base->count + overlay->count) {
         new_vals = apr_palloc(p, sizeof(apr_hash_entry_t) *
@@ -445,7 +460,11 @@ APR_DECLARE(apr_hash_t *) apr_hash_merge
 
     for (k = 0; k <= overlay->max; k++) {
         for (iter = overlay->array[k]; iter; iter = iter->next) {
-            i = iter->hash & res->max;
+            if (res->hash_func)
+                hash = res->hash_func(iter->key, &iter->klen);
+            else
+                hash = hashfunc_default(iter->key, &iter->klen, res->seed);
+            i = hash & res->max;
             for (ent = res->array[i]; ent; ent = ent->next) {
                 if ((ent->klen == iter->klen) &&
                     (memcmp(ent->key, iter->key, iter->klen) == 0)) {
@@ -463,7 +482,7 @@ APR_DECLARE(apr_hash_t *) apr_hash_merge
                 new_vals[j].klen = iter->klen;
                 new_vals[j].key = iter->key;
                 new_vals[j].val = iter->val;
-                new_vals[j].hash = iter->hash;
+                new_vals[j].hash = hash;
                 new_vals[j].next = res->array[i];
                 res->array[i] = &new_vals[j];
                 res->count++;
