$NetBSD: patch-scripts_bowtie2-hbb.sh,v 1.6 2024/05/24 11:32:58 bacon Exp $

# Eliminate bash dependency

--- scripts/bowtie2-hbb.sh.orig	2020-10-06 03:46:41.000000000 +0000
+++ scripts/bowtie2-hbb.sh
@@ -11,7 +11,7 @@ while getopts "sb:" opt; do
 done
 shift $(($OPTIND - 1))
 
-if [ "$branch" == "" ] ; then
+if [ "$branch" = "" ] ; then
     branch="master"
 fi
 
