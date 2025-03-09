$NetBSD: patch-scripts_migrate__to__xfconf.sh,v 1.1 2025/03/09 03:36:36 gutteridge Exp $

Fix unportable use of "==" in test operations.

--- scripts/migrate_to_xfconf.sh.orig	2024-03-26 16:47:37.000000000 +0000
+++ scripts/migrate_to_xfconf.sh
@@ -53,7 +53,7 @@ do
     [[ $USELABEL = "0" ]] && USELABEL=false || USELABEL=true
 
     # show output if "show" paramater used
-    if [ "$1" == "show" ]; then
+    if [ "$1" = "show" ]; then
         echo
         echo $f
         echo -e "   ID=\t\t$ID"
@@ -74,7 +74,7 @@ do
     fi
 
     # do the migration if the "doit" parameter is used
-    if [ "$1" == "doit" ]; then
+    if [ "$1" = "doit" ]; then
         # if panel is running, quit it
 		[[ $(pgrep xfce4-panel) ]] && xfce4-panel -q
         echo -n "...updating xfconf database for genmon-$ID..."
