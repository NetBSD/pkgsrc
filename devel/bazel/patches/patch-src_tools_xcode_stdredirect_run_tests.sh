$NetBSD: patch-src_tools_xcode_stdredirect_run_tests.sh,v 1.1 2016/03/01 20:45:31 jmmv Exp $

Fix equality operator to test for portability.

--- src/tools/xcode/stdredirect/run_tests.sh.orig	2016-02-18 09:23:17.000000000 +0000
+++ src/tools/xcode/stdredirect/run_tests.sh
@@ -66,7 +66,7 @@ while kill -0 "$IOS_PID" &>/dev/null; do
 done
 
 # If the simulator wasn't running when we started, then we should clean it up.
-if [ SIMULATOR_RUNNING == "false" ]; then
+if [ SIMULATOR_RUNNING = "false" ]; then
   osascript -e "tell application \"iOS Simulator\" to quit"
 fi
 
