$NetBSD: patch-modules_pdfium_update.sh,v 1.1 2018/12/16 08:12:16 ryoon Exp $

--- modules/pdfium/update.sh.orig	2018-12-04 23:11:55.000000000 +0000
+++ modules/pdfium/update.sh
@@ -132,9 +132,9 @@ update_readme() {
     perl -p -i -e "s/${PREFIX} [0-9A-Fa-f]+ \(.+\)/${PREFIX} ${COMMIT} (${COMMIT_DATE})/" README_MOZILLA
 }
 
-if [ "$#" == 0 ]; then
+if [ "$#" = 0 ]; then
     COMMIT_SELECTOR="master"
-elif [ "$#" == 2 -a "$1" == "--commit" ]; then
+elif [ "$#" = 2 -a "$1" = "--commit" ]; then
     COMMIT_SELECTOR="$2"
 else
     print_help
