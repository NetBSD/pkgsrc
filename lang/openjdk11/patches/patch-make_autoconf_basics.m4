$NetBSD: patch-make_autoconf_basics.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

Silence shell compatibility warnings.

--- make/autoconf/basics.m4.orig	2019-09-19 12:22:38.000000000 +0000
+++ make/autoconf/basics.m4
@@ -351,7 +351,7 @@ AC_DEFUN([BASIC_REMOVE_SYMBOLIC_LINKS],
       # Resolve file symlinks
       while test $COUNTER -lt 20; do
         ISLINK=`$LS -l $sym_link_dir/$sym_link_file | $GREP '\->' | $SED -e 's/.*-> \(.*\)/\1/'`
-        if test "x$ISLINK" == x; then
+        if test "x$ISLINK" = x; then
           # This is not a symbolic link! We are done!
           break
         fi
@@ -1152,7 +1152,7 @@ AC_DEFUN([BASIC_CHECK_GREP],
   NEEDLE_SPACES='ccc bbb aaa'
   NEEDLE_LIST=${NEEDLE_SPACES// /$'\n'}
   RESULT="$($GREP -Fvx "$STACK_LIST" <<< "$NEEDLE_LIST")"
-  if test "x$RESULT" == "x"; then
+  if test "x$RESULT" = "x"; then
     AC_MSG_RESULT([yes])
   else
     if test "x$OPENJDK_TARGET_OS" = "xaix"; then
