$NetBSD: patch-scripts_translation-update.sh,v 1.1 2021/09/23 18:38:35 nia Exp $

Use unlink instead of rm - more likely to be available in $PATH...

--- scripts/translation-update.sh.orig	2021-01-31 17:41:09.000000000 +0000
+++ scripts/translation-update.sh
@@ -100,7 +100,7 @@ updatemo()
 
   # clean the mess
   for LANGCODE in `cat locale/LINGUAS | grep -v "#"`; do
-   unlink ./locale/$LANGCODE/LC_MESSAGES/$LANGCODE.mo
+   rm -f ./locale/$LANGCODE/LC_MESSAGES/$LANGCODE.mo
   done
  else
   if [ x"$(uname -s)" = x"Linux" ]; then
