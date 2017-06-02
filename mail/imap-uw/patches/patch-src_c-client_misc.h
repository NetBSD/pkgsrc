$NetBSD: patch-src_c-client_misc.h,v 1.1 2017/06/02 05:35:21 taca Exp $

Rename hash_lookup() to unusual name to avoid conflict to other
shared libraries.  It should be internal function of libc-client.

--- src/c-client/misc.h.orig	2011-07-23 00:20:18.000000000 +0000
+++ src/c-client/misc.h
@@ -100,7 +100,7 @@ HASHTAB *hash_create (size_t size);
 void hash_destroy (HASHTAB **hashtab);
 void hash_reset (HASHTAB *hashtab);
 unsigned long hash_index (HASHTAB *hashtab,char *key);
-void **hash_lookup (HASHTAB *hashtab,char *key);
+void **hash_lookup_ (HASHTAB *hashtab,char *key);
 HASHENT *hash_add (HASHTAB *hashtab,char *key,void *data,long extra);
 void **hash_lookup_and_add (HASHTAB *hashtab,char *key,void *data,long extra);
 unsigned char hex2byte (unsigned char c1,unsigned char c2);
