$NetBSD: patch-deps_v8_tools_profiling_run-llprof.sh,v 1.1 2023/11/02 13:16:54 adam Exp $

POSIX shell portability.

--- deps/v8/tools/profiling/run-llprof.sh.orig	2015-03-31 22:13:01.000000000 +0000
+++ deps/v8/tools/profiling/run-llprof.sh
@@ -46,7 +46,7 @@ framework, then calls the low level tick
 EOF
 }
 
-if [ $# -eq 0 ] || [ "$1" == "-h" ]  || [ "$1" == "--help" ] ; then
+if [ $# -eq 0 ] || [ "$1" = "-h" ]  || [ "$1" = "--help" ] ; then
   usage
   exit 1
 fi
