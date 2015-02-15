$NetBSD: patch-osx_launcher.sh,v 1.1 2015/02/15 17:41:24 khorben Exp $

Fix portability failure.

--- osx/launcher.sh.orig	2014-06-01 16:11:26.000000000 +0000
+++ osx/launcher.sh
@@ -64,7 +64,7 @@ if test "$APPLELANGUAGES"; then
         fi
 	#This is a special case, because often the original strings are in US
 	#English and there is no translation file.
-	if test "x$L" == "xen_US"; then
+	if test "x$L" = "xen_US"; then
 	    export LANG=$L
 	    break
 	fi
@@ -74,7 +74,7 @@ if test "$APPLELANGUAGES"; then
 	    break
 	fi
 	#Same thing, but checking for any english variant.
-	if test "x${L:0:2}" == "xen"; then
+	if test "x${L:0:2}" = "xen"; then
 	    export LANG=$L
 	    break
 	fi;
@@ -114,16 +114,16 @@ if test -n $LANG; then 
 #If the language code matches the applelocale, then that's the message
 #locale; otherwise, if it's longer than two characters, then it's
 #probably a good message locale and we'll go with it.
-    if test $LANG == ${APPLELOCALE:0:5} -o $LANG != ${LANG:0:2}; then
+    if test $LANG = ${APPLELOCALE:0:5} -o $LANG != ${LANG:0:2}; then
 	export LC_MESSAGES=$LANG
 #Next try if the Applelocale is longer than 2 chars and the language
 #bit matches $LANG
-    elif test $LANG == ${APPLELOCALE:0:2} -a $APPLELOCALE > ${APPLELOCALE:0:2}; then
+    elif test $LANG = ${APPLELOCALE:0:2} -a $APPLELOCALE > ${APPLELOCALE:0:2}; then
 	export LC_MESSAGES=${APPLELOCALE:0:5}
 #Fail. Get a list of the locales in $PREFIX/share/locale that match
 #our two letter language code and pick the first one, special casing
 #english to set en_US
-    elif test $LANG == "en"; then
+    elif test $LANG = "en"; then
 	export LC_MESSAGES="en_US"
     else
 	LOC=`find $PREFIX/share/locale -name $LANG???`
