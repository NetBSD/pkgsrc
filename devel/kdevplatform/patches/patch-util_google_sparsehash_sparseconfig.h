$NetBSD: patch-util_google_sparsehash_sparseconfig.h,v 1.1 2014/02/21 20:20:42 joerg Exp $

--- util/google/sparsehash/sparseconfig.h.orig	2014-02-21 12:36:25.000000000 +0000
+++ util/google/sparsehash/sparseconfig.h
@@ -5,7 +5,7 @@
 #define GOOGLE_NAMESPACE ::google
 
 /* the location of <hash_fun.h>/<stl_hash_fun.h> */
-#define HASH_FUN_H "hash_fun.h"
+#define HASH_FUN_H <ext/hash_map>
 
 /* the location of <hash_map> */
 #define HASH_MAP_H <ext/hash_map>
