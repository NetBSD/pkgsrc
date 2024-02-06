$NetBSD: patch-kf6_port__plasma__kirigami.sh,v 1.1 2024/02/06 11:05:14 markd Exp $

fix test

--- kf6/port_plasma_kirigami.sh.orig	2023-06-21 05:20:49.000000000 +0000
+++ kf6/port_plasma_kirigami.sh
@@ -22,7 +22,7 @@ for i in $list_import; do
         echo "list2222222:::: $i";
         number=`grep 'mport org.kde.kirigami 2.20 as Kirigami' $i|wc -l`;
         echo $number;
-        if test $number == 0 ; then
+        if test $number = 0 ; then
                echo "insert import org.kde.kirigami 2.20 as Kirigam in $i";
               perl -pi -e 's,as PlasmaCore,as PlasmaCore\nimport org.kde.kirigami 2.20 as Kirigami,' $i;
         fi
@@ -36,7 +36,7 @@ for i in $list_PlasmaKirigami_file; do
         echo "list:::: $i";
         number=`grep Kirigami $i|wc -l`;
         echo $number;
-        if test $number == 1 ; then
+        if test $number = 1 ; then
               perl -pi -e 's,import org.kde.kirigami 2.20 as Kirigami\n,,' $i;
         fi
 done;
