$NetBSD: patch-hotspot_test_compiler_native_TestDirtyInt.sh,v 1.1 2016/05/06 13:37:01 ryoon Exp $

--- hotspot/test/compiler/native/TestDirtyInt.sh.orig	2016-05-06 12:11:25.000000000 +0000
+++ hotspot/test/compiler/native/TestDirtyInt.sh
@@ -40,10 +40,10 @@ echo "TESTSRC=${TESTSRC}"
 . ${TESTSRC}/../../test_env.sh
 
 # set platform-dependent variables
-if [ $VM_OS == "linux" -a $VM_CPU == "sparcv9" ]; then
+if [ $VM_OS = "linux" -a $VM_CPU = "sparcv9" ]; then
     echo "Testing on linux-sparc"
     gcc_cmd=`which gcc`
-    if [ "x$gcc_cmd" == "x" ]; then
+    if [ "x$gcc_cmd" = "x" ]; then
         echo "WARNING: gcc not found. Cannot execute test." 2>&1
         exit 0;
     fi
