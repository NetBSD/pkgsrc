$NetBSD: patch-lang_compile__mo.sh,v 1.2 2021/07/12 20:54:02 nia Exp $

Shell portability.

--- lang/compile_mo.sh.orig	2021-07-03 05:00:06.000000000 +0000
+++ lang/compile_mo.sh
@@ -26,7 +26,7 @@ then
     for n in $@
     do
         f="lang/po/${n}.po"
-        if ( [ "$n" == "en" ]) && ((! [ "${os##CYGWIN*}" ]) || (! [ "${os##MINGW*}" ])); then
+        if ( [ "$n" = "en" ]) && ((! [ "${os##CYGWIN*}" ]) || (! [ "${os##MINGW*}" ])); then
             # English is special: we do not actually need translation for English,
             # but due to a libintl bug (https://savannah.gnu.org/bugs/index.php?58006),
             # gettext would be extremely slow on MinGW targets if we do not compile
