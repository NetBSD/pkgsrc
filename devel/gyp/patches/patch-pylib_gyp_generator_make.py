$NetBSD: patch-pylib_gyp_generator_make.py,v 1.1 2013/01/18 11:32:45 ryoon Exp $

--- pylib/gyp/generator/make.py.orig	2012-12-15 10:46:06.000000000 +0000
+++ pylib/gyp/generator/make.py
@@ -328,7 +328,7 @@ sed -e "s|^$(notdir $@)|$@|" $(depfile).
 # We remove slashes and replace spaces with new lines;
 # remove blank lines;
 # delete the first line and append a colon to the remaining lines.
-sed -e 's|\\||' -e 'y| |\n|' $(depfile).raw |\
+env NL=`printf "\n"` sed -e 's|\\||' -e 's| |${NL}|g' $(depfile).raw |\
   grep -v '^$$'                             |\
   sed -e 1d -e 's|$$|:|'                     \
     >> $(depfile)
