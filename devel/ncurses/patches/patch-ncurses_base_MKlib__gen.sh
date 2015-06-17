$NetBSD: patch-ncurses_base_MKlib__gen.sh,v 1.1 2015/06/17 14:20:03 jperkin Exp $

* Pull in upstream fix for GCC 5.1 (http://trac.sagemath.org/ticket/18301)

--- ncurses/base/MKlib_gen.sh.orig	2015-06-16 02:49:42.375000000 +0000
+++ ncurses/base/MKlib_gen.sh
@@ -437,11 +437,22 @@ sed -n -f $ED1 \
 	-e 's/gen_$//' \
 	-e 's/  / /g' >>$TMP
 
+cat >$ED1 <<EOF
+s/  / /g
+s/^ //
+s/ $//
+s/P_NCURSES_BOOL/NCURSES_BOOL/g
+EOF
+
+# A patch discussed here:
+#       https://gcc.gnu.org/ml/gcc-patches/2014-06/msg02185.html
+# introduces spurious #line markers.  Work around that by ignoring the system's
+# attempt to define "bool" and using our own symbol here.
+sed -e 's/bool/P_NCURSES_BOOL/g' $TMP > $ED2
+cat $ED2 >$TMP
+
 $preprocessor $TMP 2>/dev/null \
-| sed \
-	-e 's/  / /g' \
-	-e 's/^ //' \
-	-e 's/_Bool/NCURSES_BOOL/g' \
+| sed -f $ED1 \
 | $AWK -f $AW2 \
 | sed -f $ED3 \
 | sed \
