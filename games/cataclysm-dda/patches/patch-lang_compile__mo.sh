$NetBSD: patch-lang_compile__mo.sh,v 1.1 2020/04/30 14:57:30 nia Exp $

Shell portability.

--- lang/compile_mo.sh.orig	2020-04-01 05:39:38.000000000 +0000
+++ lang/compile_mo.sh
@@ -24,7 +24,7 @@ then
     for n in $@
     do
         f="lang/po/${n}.po"
-        if [ $n == "en" ]; then
+        if [ $n = "en" ]; then
             # English is special: we do not actually need translation for English,
             # but due to a libintl bug (https://savannah.gnu.org/bugs/index.php?58006),
             # gettext would be extremely slow on MinGW targets if we do not compile
