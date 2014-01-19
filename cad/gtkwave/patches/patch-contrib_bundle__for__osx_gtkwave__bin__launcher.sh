$NetBSD: patch-contrib_bundle__for__osx_gtkwave__bin__launcher.sh,v 1.1 2014/01/19 09:25:18 mef Exp $

ERROR: [check-portability.awk] => Found test ... == ...:

--- contrib/bundle_for_osx/gtkwave_bin_launcher.sh~	2013-10-16 04:18:04.000000000 +0900
+++ contrib/bundle_for_osx/gtkwave_bin_launcher.sh	2013-12-21 16:32:27.000000000 +0900
@@ -28,7 +28,7 @@ fi
 
 export OWD="`pwd`"
 
-if [[ $(echo $0 | awk '/^\//') == $0 ]]; then
+if [[ $(echo $0 | awk '/^\//') = $0 ]]; then
     export NNAM=$(dirname $0)
     name="$NNAM"
     bundle="$NNAM/../../.."
@@ -81,7 +81,7 @@ if test "$APPLELANGUAGES"; then
         fi
 	#This is a special case, because often the original strings are in US
 	#English and there is no translation file.
-	if test "x$L" == "xen_US"; then
+	if test "x$L" = "xen_US"; then
 	    export LANG=$L
 	    break
 	fi
@@ -91,7 +91,7 @@ if test "$APPLELANGUAGES"; then
 	    break
 	fi
 	#Same thing, but checking for any english variant.
-	if test "x${L:0:2}" == "xen"; then
+	if test "x${L:0:2}" = "xen"; then
 	    export LANG=$L
 	    break
 	fi;
@@ -146,7 +146,7 @@ if test -n $LANG; then 
 #english to set en_US
 
 #   elif test $LANG == "en"; then
-    if test $LANG == "en"; then
+    if test $LANG = "en"; then
 	export LC_MESSAGES="en_US"
     else
 	LOC=`find $PREFIX/share/locale -name $LANG???`
