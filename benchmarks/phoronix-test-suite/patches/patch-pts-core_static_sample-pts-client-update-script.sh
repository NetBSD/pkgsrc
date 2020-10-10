$NetBSD: patch-pts-core_static_sample-pts-client-update-script.sh,v 1.1 2020/10/10 12:57:41 mef Exp $

ERROR: [check-portability.awk] => Found test ... == ...

--- pts-core/static/sample-pts-client-update-script.sh.orig	2019-05-30 15:01:30.000000000 +0000
+++ pts-core/static/sample-pts-client-update-script.sh
@@ -20,7 +20,7 @@ fi
 cd /phoronix-test-suite
 CURRENT_GIT_COMMIT=`git rev-parse HEAD`
 
-if [ "$GIT_COMMIT_TO_USE" != "$CURRENT_GIT_COMMIT" ] || [ "$FRESH_CLONE" == "1" ]
+if [ "$GIT_COMMIT_TO_USE" != "$CURRENT_GIT_COMMIT" ] || [ "$FRESH_CLONE" = "1" ]
 then
 	git checkout master
 	git pull
