$NetBSD: patch-kf6_port__plasma__ksvg.sh,v 1.1 2024/02/06 11:05:14 markd Exp $

fix test

--- kf6/port_plasma_ksvg.sh.orig	2023-06-21 05:20:49.000000000 +0000
+++ kf6/port_plasma_ksvg.sh
@@ -12,7 +12,7 @@ for i in $list_import; do
         echo "list $i";
         number=`grep 'import org.kde.ksvg 1.0 as KSvg' $i|wc -l`;
         echo $number;
-        if test $number == 0 ; then
+        if test $number = 0 ; then
                echo "import org.kde.ksvg 1.0 as KSvg in $i";
               perl -pi -e 's,as PlasmaCore,as PlasmaCore\nimport org.kde.ksvg 1.0 as KSvg,' $i;
         fi
@@ -25,7 +25,7 @@ for i in $list_PlasmaKirigami_file; do
         echo "list:::: $i";
         number=`grep KSvg $i|wc -l`;
         echo $number;
-        if test $number == 1 ; then
+        if test $number = 1 ; then
               perl -pi -e 's,import org.kde.ksvg 1.0 as KSvg\n,,' $i;
         fi
 done;
