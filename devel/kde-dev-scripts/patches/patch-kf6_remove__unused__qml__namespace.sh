$NetBSD: patch-kf6_remove__unused__qml__namespace.sh,v 1.1 2024/02/06 11:05:14 markd Exp $

fix test

--- kf6/remove_unused_qml_namespace.sh.orig	2023-06-21 05:20:49.000000000 +0000
+++ kf6/remove_unused_qml_namespace.sh
@@ -8,7 +8,7 @@ for f in $list_qml; do
         	#echo "import namespace $i";
 	        number=`grep $i $f|wc -l`;
 		#echo "number namespace '$i' $number in  $f";
-		if test $number == 1 ; then
+		if test $number = 1 ; then
 			echo "remove $i in file $f";
 			perl -pi -e "s,import.* as $i\n,," $f;
 		fi
