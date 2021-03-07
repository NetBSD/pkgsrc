$NetBSD: patch-build_libtool.m4,v 1.1 2021/03/07 13:11:06 taca Exp $

Stop warnings on newer autoconf.

--- build/libtool.m4.orig	2021-03-02 10:35:17.000000000 +0000
+++ build/libtool.m4
@@ -676,8 +676,11 @@ s390*-*linux*|sparc*-*linux*)
   CFLAGS="$CFLAGS -belf"
   AC_CACHE_CHECK([whether the C compiler needs -belf], lt_cv_cc_needs_belf,
     [AC_LANG_SAVE
-     AC_LANG_C
-     AC_TRY_LINK([],[],[lt_cv_cc_needs_belf=yes],[lt_cv_cc_needs_belf=no])
+     AC_LANG([C])
+     AC_LINK_IFELSE(
+       [AC_LANG_PROGRAM([],[])],
+       [lt_cv_cc_needs_belf=yes],
+       [lt_cv_cc_needs_belf=no])
      AC_LANG_RESTORE])
   if test x"$lt_cv_cc_needs_belf" != x"yes"; then
     # this is probably gcc 2.8.0, egcs 1.0 or newer; no need for -belf
@@ -1196,7 +1199,7 @@ if test "$_LT_AC_TAGVAR(lt_cv_prog_compi
   ln conftest.a conftest.b 2>/dev/null && hard_links=no
   AC_MSG_RESULT([$hard_links])
   if test "$hard_links" = no; then
-    AC_MSG_WARN([\`$CC' does not support \`-c -o', so \`make -j' may be unsafe])
+    AC_MSG_WARN([`$CC' does not support `-c -o', so `make -j' may be unsafe])
     need_locks=warn
   fi
 else
@@ -1923,15 +1926,15 @@ AC_ARG_WITH([tags],
 
 if test -f "$ltmain" && test -n "$tagnames"; then
   if test ! -f "${ofile}"; then
-    AC_MSG_WARN([output file \`$ofile' does not exist])
+    AC_MSG_WARN([output file `$ofile' does not exist])
   fi
 
   if test -z "$LTCC"; then
     eval "`$SHELL ${ofile} --config | grep '^LTCC='`"
     if test -z "$LTCC"; then
-      AC_MSG_WARN([output file \`$ofile' does not look like a libtool script])
+      AC_MSG_WARN([output file `$ofile' does not look like a libtool script])
     else
-      AC_MSG_WARN([using \`LTCC=$LTCC', extracted from \`$ofile'])
+      AC_MSG_WARN([using `LTCC=$LTCC', extracted from `$ofile'])
     fi
   fi
   if test -z "$LTCFLAGS"; then
@@ -1954,7 +1957,7 @@ if test -f "$ltmain" && test -n "$tagnam
 
     if grep "^# ### BEGIN LIBTOOL TAG CONFIG: $tagname$" < "${ofile}" > /dev/null
     then
-      AC_MSG_ERROR([tag name \"$tagname\" already exists])
+      AC_MSG_ERROR([tag name "$tagname" already exists])
     fi
 
     # Update the list of available tags.
@@ -2727,7 +2730,7 @@ AC_DEFUN([AC_LIBTOOL_LANG_C_CONFIG], [_L
 AC_DEFUN([_LT_AC_LANG_C_CONFIG],
 [lt_save_CC="$CC"
 AC_LANG_SAVE
-AC_LANG_C
+AC_LANG([C])
 
 # Source file extension for C test sources.
 ac_ext=c
@@ -2808,7 +2811,7 @@ CC="$lt_save_CC"
 AC_DEFUN([AC_LIBTOOL_LANG_CXX_CONFIG], [_LT_AC_LANG_CXX_CONFIG(CXX)])
 AC_DEFUN([_LT_AC_LANG_CXX_CONFIG],
 [AC_LANG_SAVE
-AC_LANG_CPLUSPLUS
+AC_LANG([C++])
 AC_REQUIRE([AC_PROG_CXX])
 AC_REQUIRE([_LT_AC_PROG_CXXCPP])
 
