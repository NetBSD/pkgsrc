$NetBSD: patch-frontends_php_locale_add__new__language.sh,v 1.2 2019/02/07 12:36:25 he Exp $

Fix bash scripts to use normal shell constructs.

--- frontends/php/locale/add_new_language.sh.orig	2017-05-05 14:50:32.000000000 +0000
+++ frontends/php/locale/add_new_language.sh
@@ -2,7 +2,7 @@
 
 messagetemplate=frontend.pot
 
-[[ $1 ]] || {
+[ -n "$1" ] || {
 	echo "Specify language code"
 	exit 1
 }
