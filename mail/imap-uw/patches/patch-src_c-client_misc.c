$NetBSD: patch-src_c-client_misc.c,v 1.1 2017/06/02 05:35:21 taca Exp $

Rename hash_lookup() to unusual name to avoid conflict to other
shared libraries.  It should be internal function of libc-client.

--- src/c-client/misc.c.orig	2011-07-23 00:20:18.000000000 +0000
+++ src/c-client/misc.c
@@ -343,7 +343,7 @@ unsigned long hash_index (HASHTAB *hasht
  * Returns: associated data
  */
 
-void **hash_lookup (HASHTAB *hashtab,char *key)
+void **hash_lookup_ (HASHTAB *hashtab,char *key)
 {
   HASHENT *ret;
   for (ret = hashtab->table[hash_index (hashtab,key)]; ret; ret = ret->next)
