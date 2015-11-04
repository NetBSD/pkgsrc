$NetBSD: patch-libtme_memory-auto.sh,v 1.3 2015/11/04 03:33:39 dholland Exp $

--- libtme/memory-auto.sh.orig	2010-02-15 15:16:28.000000000 +0000
+++ libtme/memory-auto.sh
@@ -96,6 +96,8 @@ EOF
 if $header; then
     cat <<EOF
 
+#include <limits.h>
+#include <stdint.h>
 /* macros: */
 
 /* the plain partial read internal macro: */
@@ -129,7 +130,7 @@ if $header; then
 
 /* this returns a mask of all-bits-one in given type: */
 #define _tme_memory_type_mask(type, shift)				\\
-  ((type) ((((type) 0) - ((type) 1)) shift))
+  ((type) (UINTMAX_MAX shift))
 
 EOF
 fi
