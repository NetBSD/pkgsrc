$NetBSD: patch-xtra_pgscript_file_test_execute.sh,v 1.1 2013/07/20 05:10:42 richard Exp $

Patch non-portable test for null string

--- xtra/pgscript/file/test/execute.sh.orig	2012-08-02 14:29:10.000000000 +0000
+++ xtra/pgscript/file/test/execute.sh
@@ -24,7 +24,7 @@ echo "done"
 echo ""
 
 # Get parameters for database connections
-if test "$*" == ""
+if test -z "$*"
 then
 	PARAMETERS="$DEFAULTPARAM" # Default if nothing is provided
 else
