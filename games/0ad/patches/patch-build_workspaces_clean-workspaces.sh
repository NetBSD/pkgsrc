$NetBSD: patch-build_workspaces_clean-workspaces.sh,v 1.1 2023/05/04 15:20:52 nikita Exp $


--- -build/workspaces/clean-workspaces.sh.orig	2022-08-21 14:46:47.000000000 +0200
+++ build/workspaces/clean-workspaces.sh	2023-05-03 20:01:25.557929713 +0200
@@ -3,7 +3,7 @@
 # Some of our makefiles depend on GNU make, so we set some sane defaults if MAKE
 # is not set.
 case "`uname -s`" in
-  "FreeBSD" | "OpenBSD" )
+  "FreeBSD" | "NetBSD" | "OpenBSD" )
     MAKE=${MAKE:="gmake"}
     ;;
   * )
@@ -64,7 +64,7 @@
 echo "Removing generated stub and test files..."
 
 find ../../source -name "stub_*.cpp" -type f -exec rm {} \;
-find ../../source -name "test_*.cpp" -type f -not -name "test_setup.cpp" -exec rm {} \;
+find ../../source -name "test_*.cpp" -type f ! -name "test_setup.cpp" -exec rm {} \;
 
 echo "Cleaning build output..."
 
