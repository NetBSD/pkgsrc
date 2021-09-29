$NetBSD: patch-tools_build_src_engine_build.sh,v 1.4 2021/09/29 16:11:04 adam Exp $

Fix for bad substitution.

--- tools/build/src/engine/build.sh.orig	2021-08-05 09:43:08.000000000 +0000
+++ tools/build/src/engine/build.sh
@@ -23,9 +23,7 @@ B2_CXXFLAGS_OPT=
 # We need to calculate and set SCRIPT_PATH and SCRIPT_DIR to reference this
 # script so that we can refer to file relative to it.
 SCRIPT_PATH=""
-if test "${BASH_SOURCE}" ; then
     SCRIPT_PATH=${BASH_SOURCE}
-fi
 if test "${SCRIPT_PATH}" = "" ; then
     SCRIPT_PATH=$0
 fi
