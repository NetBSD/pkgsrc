$NetBSD: patch-frontends_php_locale_add__new__language.sh,v 1.1 2017/07/03 13:04:01 joerg Exp $

--- frontends/php/locale/add_new_language.sh.orig	2017-05-05 14:50:32.000000000 +0000
+++ frontends/php/locale/add_new_language.sh
@@ -2,7 +2,7 @@
 
 messagetemplate=frontend.pot
 
-[[ $1 ]] || {
+[ -n "$1" ] || {
 	echo "Specify language code"
 	exit 1
 }
