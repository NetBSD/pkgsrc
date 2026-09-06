$NetBSD: patch-Messages.sh,v 1.1 2026/09/06 11:03:04 markd Exp $

fix "test =="

--- Messages.sh.orig	2026-08-14 03:27:38.000000000 +0000
+++ Messages.sh
@@ -9,7 +9,7 @@ for file in data/layouts/*.json; do
     if [ -f "$file" ]; then
         name_string=$(jq '.kdenliveInfo[] | .displayName' $file)
         # Use the same syntax as extractrc
-        if [ $name_string == "null" ]; then
+        if [ $name_string = "null" ]; then
             echo "Layout without name: $file"
         else
             echo "// i18n: file: $file" >> rc.cpp
