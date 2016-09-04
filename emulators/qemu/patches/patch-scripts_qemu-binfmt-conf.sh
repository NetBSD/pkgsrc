$NetBSD: patch-scripts_qemu-binfmt-conf.sh,v 1.1 2016/09/04 09:21:04 ryoon Exp $

* POSIX shell portability

--- scripts/qemu-binfmt-conf.sh.orig	2016-09-02 15:34:23.000000000 +0000
+++ scripts/qemu-binfmt-conf.sh
@@ -279,12 +279,12 @@ while true ; do
         shift
         # check given cpu is in the supported CPU list
         for cpu in ${qemu_target_list} ; do
-            if [ "$cpu" == "$1" ] ; then
+            if [ "$cpu" = "$1" ] ; then
                 break
             fi
         done
 
-        if [ "$cpu" == "$1" ] ; then
+        if [ "$cpu" = "$1" ] ; then
             qemu_target_list="$1"
         else
             echo "ERROR: unknown CPU \"$1\"" 1>&2
