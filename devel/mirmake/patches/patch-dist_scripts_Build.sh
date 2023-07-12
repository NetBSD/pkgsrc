$NetBSD: patch-dist_scripts_Build.sh,v 1.1 2023/07/12 19:34:39 vins Exp $

Support pdksh.
Do not require perl.

--- dist/scripts/Build.sh.orig	2014-12-20 22:34:27.000000000 +0000
+++ dist/scripts/Build.sh
@@ -66,6 +66,7 @@
 export SHELL=$new_mirksh
 unset MAKE
 
+[[ -n $KSH_VERSION ]] && set -o braceexpand
 [[ -n $BASH_VERSION ]] && shopt -s extglob
 
 # Directories
@@ -262,9 +263,13 @@
 	}
 EOF
 $CC $CFLAGS -o _t.exe _t.c -Werror || rm -f _t.exe
-[[ -x _t.exe ]] || perl -pi -e \
-    's/__attribute__\s*\(\(\s*_*bounded_*\s*\([^)]*\)\s*\)\)//' \
-    $(find . -name \*.[ch])
+[[ -x _t.exe ]] || find . -name \*.[ch] -exec sh -c '
+    T=/tmp/mirmake.$$.tmp
+    B='[[:blank:]]'
+    sed -e "s/__attribute__$B*(($B*_*bounded_*$B*([^)]*)$B*))//" {} > $T
+    test $? -eq 0 -a -s $T   || { rm -f $T; exit 1; }	  # error, bogus: delete
+    cmp -s {} $T || mv $T {} || { rm -f $T; exit 1; }	  # rename failed:  "
+    test -f $T && rm -f $T			     ' \; # unchanged file: "
 rm -f _t.*
 
 if [[ $binown = - ]]; then
