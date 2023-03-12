$NetBSD: patch-tools_gfind__missing__files_gfind__missing__files.sh,v 1.1 2023/03/12 11:55:59 js Exp $

NetBSD build fixes
From upstream https://review.gluster.org/24648

--- tools/gfind_missing_files/gfind_missing_files.sh.orig	2018-04-12 17:46:46.697237625 +0000
+++ tools/gfind_missing_files/gfind_missing_files.sh
@@ -61,7 +61,7 @@ mount_slave()
 
 parse_cli()
 {
-    if [[ $# -ne 4 ]]; then
+    if [ "$#" -ne 4 ]; then
         echo "Usage: gfind_missing_files <brick-path> <slave-host> <slave-vol> <OUTFILE>"
         exit 1
     else
