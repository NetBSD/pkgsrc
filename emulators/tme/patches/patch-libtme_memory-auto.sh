$NetBSD: patch-libtme_memory-auto.sh,v 1.1 2015/09/13 15:08:09 joerg Exp $

--- libtme/memory-auto.sh.orig	2015-09-03 14:35:30.000000000 +0000
+++ libtme/memory-auto.sh
@@ -129,7 +129,7 @@ if $header; then
 
 /* this returns a mask of all-bits-one in given type: */
 #define _tme_memory_type_mask(type, shift)				\\
-  ((type) ((((type) 0) - ((type) 1)) shift))
+  ((type) (UINTMAX_MAX shift))
 
 EOF
 fi
