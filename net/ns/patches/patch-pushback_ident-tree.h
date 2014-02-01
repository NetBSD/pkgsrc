$NetBSD: patch-pushback_ident-tree.h,v 1.1 2014/02/01 08:04:04 markd Exp $

Fix invalid conversion from 'void*' to 'char*'

--- pushback/ident-tree.h.orig	2005-09-18 23:33:34.000000000 +0000
+++ pushback/ident-tree.h
@@ -83,7 +83,7 @@ class DropHashTable {
     Tcl_HashSearch searchPtr;
     Tcl_HashEntry * he = Tcl_FirstHashEntry(hashTable_, &searchPtr);
     while (he != NULL) {
-      char * key = Tcl_GetHashKey(hashTable_, he);
+      char * key = (char *) Tcl_GetHashKey(hashTable_, he);
       long value = (long)Tcl_GetHashValue(he);
       printf("%s = %ld\n", key, value);
       he = Tcl_NextHashEntry(&searchPtr);
