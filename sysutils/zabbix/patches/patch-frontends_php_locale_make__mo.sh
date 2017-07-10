$NetBSD: patch-frontends_php_locale_make__mo.sh,v 1.1.2.2 2017/07/10 19:52:29 bsiegert Exp $

--- frontends/php/locale/make_mo.sh.orig	2017-05-05 14:50:27.000000000 +0000
+++ frontends/php/locale/make_mo.sh
@@ -1,5 +1,5 @@
 #!/bin/bash
 
-while read pofile; do
+find $(dirname $0) -type f ! -wholename '*/.svn*' -name '*.po' | while read pofile; do
         msgfmt --use-fuzzy -c -o ${pofile%po}mo $pofile
-done < <(find $(dirname $0) -type f ! -wholename '*/.svn*' -name '*.po')
+done
