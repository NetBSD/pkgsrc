$NetBSD: patch-gnats_ds-file_mkcat.sh,v 1.1 2015/04/19 19:35:00 spz Exp $

use full path

--- gnats/ds-file/mkcat.sh.orig	2014-12-28 19:02:35.000000000 +0000
+++ gnats/ds-file/mkcat.sh
@@ -38,7 +38,7 @@ while [ "$#" -gt 0 ]; do
   shift
 done
 
-QUERY_PR="query-pr"
+QUERY_PR="xBINDIRx/query-pr"
 GNATS_DB_DIR=`"$QUERY_PR" --print-directory-for-database` || exit
 
 # verify gnats root
