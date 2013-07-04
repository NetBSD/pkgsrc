$NetBSD: patch-tools_dev_benchmarks_large__dirs_create__bigdir.sh,v 1.1 2013/07/04 19:31:15 wiz Exp $

Fix unportable test(1) construct.

--- tools/dev/benchmarks/large_dirs/create_bigdir.sh.orig	2012-05-21 00:23:26.000000000 +0000
+++ tools/dev/benchmarks/large_dirs/create_bigdir.sh
@@ -199,7 +199,7 @@ while [ $FILECOUNT -lt $MAXCOUNT ]; do
   run_svn_del ${FILECOUNT} 1
 
   printf "\tDeleting files ... \t"
-  if [ "$FILECOUNT" == "1" ] ; then
+  if [ "$FILECOUNT" = "1" ] ; then
     printf " skipped (0 files to delete)\n"
   else
     run_svn_del_many ${FILECOUNT}
