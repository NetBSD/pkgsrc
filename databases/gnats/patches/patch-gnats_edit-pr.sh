$NetBSD: patch-gnats_edit-pr.sh,v 1.1 2015/04/19 19:35:00 spz Exp $

clean up temp files

--- gnats/edit-pr.sh.orig	2015-02-26 04:26:41.000000000 +0000
+++ gnats/edit-pr.sh
@@ -213,6 +213,7 @@ $VISUAL $new
 if cmp -s $new.old $new ; then
   echo "edit-pr: PR not changed"
   $PR_EDIT --unlock $pr_id
+  rm $new $new.old
   exit 0
 fi
 
@@ -239,6 +240,7 @@ while [ "$checking" != "" ]; do
         echo "PR $pr_id not updated: changed file is in $new.changed"
         mv $new $new.changed
 	$PR_EDIT --unlock $pr_id
+        rm $new $new.old
         exit 0
         ;;
     esac
@@ -269,6 +271,7 @@ done
 if [ -f $change_msg ]
 then
     cat $change_msg >> $new
+    rm $change_msg
 fi
 
 if email=`$QUERY_PR \
@@ -290,6 +293,7 @@ while true; do
 	echo "Edit successful"
 	# we need to unlock the PR
 	$PR_EDIT --unlock $pr_id
+        rm $new $new.old
 	exit 0
     else
 	echo "Problems with edit submission."
@@ -302,6 +306,7 @@ while true; do
 		echo "Cancelling edit.  Changed PR is in $new."
 		# we need to ulock the PR no matter what
 		$PR_EDIT --unlock $pr_id
+                rm $new.old
 		exit 1 ;;
 	    r*)
 		break ;;
@@ -312,6 +317,6 @@ while true; do
     done
 done
 
-rm -f $new
+rm -f $new $new.old
 
 exit 0
