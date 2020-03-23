$NetBSD: patch-tools_gfind__missing__files_gfind__missing__files.sh,v 1.1 2020/03/23 23:21:17 gdt Exp $

Remediate bashism.

Not yet filed upstream.

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
