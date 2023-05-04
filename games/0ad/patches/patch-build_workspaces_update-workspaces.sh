$NetBSD: patch-build_workspaces_update-workspaces.sh,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- build/workspaces/update-workspaces.sh.orig	2021-07-27 21:57:40.000000000 +0000
+++ build/workspaces/update-workspaces.sh
@@ -1,10 +1,5 @@
 #!/bin/sh
 
-if [ "$(id -u)" = "0" ]; then
-   echo "Running as root will mess up file permissions. Aborting ..." 1>&2
-   exit 1
-fi
-
 die()
 {
   echo ERROR: $*
@@ -26,7 +21,7 @@ JOBS=${JOBS:="-j2"}
 # Some of our makefiles depend on GNU make, so we set some sane defaults if MAKE
 # is not set.
 case "`uname -s`" in
-  "FreeBSD" | "OpenBSD" )
+  "FreeBSD" | "NetBSD" | "OpenBSD" )
     MAKE=${MAKE:="gmake"}
     ;;
   * )
@@ -120,11 +115,14 @@ if [ "$with_system_premake5" = "false" ]
   ${MAKE} -C $PREMAKE_BUILD_DIR ${JOBS} || die "Premake build failed"
 
   premake_command="premake5/bin/release/premake5"
+  cd ..
+else
+  cd ../premake
 fi
+# Now in build/premake subdirectory
 
 echo
 
-cd ..
 
 # If we're in bash then make HOSTTYPE available to Premake, for primitive arch-detection
 export HOSTTYPE="$HOSTTYPE"
