$NetBSD: patch-cmd_gvmap_gvmap.sh,v 1.1 2020/03/13 15:16:00 tnn Exp $

shell portability issues

--- cmd/gvmap/gvmap.sh.orig	2016-08-09 21:02:09.000000000 +0000
+++ cmd/gvmap/gvmap.sh
@@ -64,7 +64,7 @@ do
     exit 2
     ;;
   \? )
-    if [[ "$OPTARG" == '?' ]]
+    if [ "$OPTARG" = '?' ]
     then
       getopts -a gvmap "$OPTSTR" x '-?'
       exit 0
@@ -76,9 +76,9 @@ do
 done
 shift $((OPTIND-1))
 
-if [[ $# == 0 ]]
+if [ $# = 0 ]
 then
-  if [[ -n $VERBOSE ]]
+  if [ -n $VERBOSE ]
   then
     print -u 2 "$LAYOUT -Goverlap=prism $FLAGS1 | gvmap $FLAGS2 | neato -n2 $FLAGS3"
   fi
@@ -86,9 +86,9 @@ then
 else
   while (( $# > 0 ))
   do
-    if [[ -f $1 ]]
+    if [ -f $1 ]
     then
-      if [[ -n $VERBOSE ]]
+      if [ -n $VERBOSE ]
       then
         print -u 2 "$LAYOUT -Goverlap=prism $FLAGS1 $1 | gvmap $FLAGS2 | neato -n2 $FLAGS3"
       fi
