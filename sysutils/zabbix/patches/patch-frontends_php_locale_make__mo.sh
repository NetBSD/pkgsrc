$NetBSD: patch-frontends_php_locale_make__mo.sh,v 1.3 2020/09/17 13:52:15 otis Exp $

Make script runnable with non-bash bourne shell.

--- frontends/php/locale/make_mo.sh.orig	2020-09-13 19:14:35.190972278 +0000
+++ frontends/php/locale/make_mo.sh
@@ -1,5 +1,6 @@
 #!/bin/bash
 
-while read pofile; do
+find $(dirname $0) -type f ! -wholename '*/.svn*' -name '*.po' | \
+   while read pofile; do
         msgfmt --use-fuzzy -c -o ${pofile%po}mo $pofile || exit $?
-done < <(find $(dirname $0) -type f -name '*.po')
+done
