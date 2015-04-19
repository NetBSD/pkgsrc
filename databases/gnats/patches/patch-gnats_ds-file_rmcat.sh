$NetBSD: patch-gnats_ds-file_rmcat.sh,v 1.1 2015/04/19 19:35:00 spz Exp $

call query-pr with full path

--- gnats/ds-file/rmcat.sh.orig	2014-12-28 19:02:36.000000000 +0000
+++ gnats/ds-file/rmcat.sh
@@ -28,7 +28,8 @@ if [ $# -eq 0 ]; then
   exit 1
 fi
 
-GNATS_DB_DIR="`query-pr --print-directory-for-database`"
+QUERY_PR="xBINDIRx/query-pr"
+GNATS_DB_DIR="`$QUERY_PR --print-directory-for-database`"
 
 if [ ! -d "$GNATS_DB_DIR" ]
 then
@@ -37,7 +38,7 @@ then
 fi
 
 for i in "$@"; do
-    if query-pr --list-categories | grep "^${i}:" >/dev/null 2>&1; then
+    if $QUERY_PR --list-categories | grep "^${i}:" >/dev/null 2>&1; then
       echo "$prog: category \`$i' is still in the categories file, please remove it."
       continue
     fi
