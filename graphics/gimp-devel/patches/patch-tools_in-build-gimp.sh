$NetBSD: patch-tools_in-build-gimp.sh,v 1.1 2025/02/11 13:15:13 ryoon Exp $

* Do not use gdb during build.

--- tools/in-build-gimp.sh.orig	2025-02-11 12:53:23.323362498 +0000
+++ tools/in-build-gimp.sh
@@ -24,13 +24,8 @@ if [ -n "$GIMP_TEMP_UPDATE_RPATH" ]; the
   unset IFS
 fi
 
-if command -v gdb; then
-  echo RUNNING: cat /dev/stdin "|" gdb --batch -x "$GIMP_GLOBAL_SOURCE_ROOT/tools/debug-in-build-gimp.py" --args $GIMP_SELF_IN_BUILD "$@"
-  cat /dev/stdin | gdb --return-child-result --batch -x "$GIMP_GLOBAL_SOURCE_ROOT/tools/debug-in-build-gimp.py" --args $GIMP_SELF_IN_BUILD "$@"
-else
   echo RUNNING: cat /dev/stdin "|" $GIMP_SELF_IN_BUILD "$@"
   cat /dev/stdin | $GIMP_SELF_IN_BUILD "$@"
-fi
 
 if [ -n "$GIMP_TEMP_UPDATE_RPATH" ]; then
   export IFS=":"
