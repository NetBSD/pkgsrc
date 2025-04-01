$NetBSD: patch-scripts_common.m4,v 1.1 2025/04/01 09:37:04 adam Exp $

Portability fix.

--- scripts/common.m4.orig	2025-04-01 09:23:31.361110823 +0000
+++ scripts/common.m4
@@ -28,8 +28,7 @@ AC_DEFUN([TORRENT_REMOVE_UNWANTED],
   if test -z "${unwanted_values}"; then
     $1="$2"
   else
-    result=`echo "${values_to_check}" | $GREP -Fvx -- "${unwanted_values}" | $GREP -v '^$'`
-    $1=${result//$'\n'/ }
+    $1=`echo "${values_to_check}" | $GREP -Fvx -- "${unwanted_values}" | $GREP -v '^$' | tr '\n' ' '`
   fi
 ])
 
