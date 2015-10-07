$NetBSD: patch-libtme_memory-auto.sh,v 1.2 2015/10/07 23:16:58 joerg Exp $

--- libtme/memory-auto.sh.orig	2010-02-15 15:16:28.000000000 +0000
+++ libtme/memory-auto.sh
@@ -96,6 +96,7 @@ EOF
 if $header; then
     cat <<EOF
 
+#include <limits.h>
 /* macros: */
 
 /* the plain partial read internal macro: */
@@ -129,7 +130,7 @@ if $header; then
 
 /* this returns a mask of all-bits-one in given type: */
 #define _tme_memory_type_mask(type, shift)				\\
-  ((type) ((((type) 0) - ((type) 1)) shift))
+  ((type) (UINTMAX_MAX shift))
 
 EOF
 fi
