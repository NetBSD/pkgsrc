$NetBSD: patch-contrib_bundle__for__osx_launcher.sh,v 1.1 2014/01/19 09:25:18 mef Exp $

ERROR: [check-portability.awk] => Found test ... == ...:

--- contrib/bundle_for_osx/launcher.sh~	2013-10-22 03:27:08.000000000 +0900
+++ contrib/bundle_for_osx/launcher.sh	2013-12-21 16:28:17.000000000 +0900
@@ -54,7 +54,7 @@ if test "$APPLELANGUAGES"; then
         fi
 	#This is a special case, because often the original strings are in US
 	#English and there is no translation file.
-	if test "x$L" == "xen_US"; then
+	if test "x$L" = "xen_US"; then
 	    export LANG=$L
 	    break
 	fi
@@ -64,7 +64,7 @@ if test "$APPLELANGUAGES"; then
 	    break
 	fi
 	#Same thing, but checking for any english variant.
-	if test "x${L:0:2}" == "xen"; then
+	if test "x${L:0:2}" = "xen"; then
 	    export LANG=$L
 	    break
 	fi;
@@ -104,16 +104,16 @@ if test -n $LANG; then 
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
