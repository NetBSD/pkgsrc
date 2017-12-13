$NetBSD: patch-m4_cares-compilers.m4,v 1.1 2017/12/13 15:15:45 jperkin Exp $

Don't strip out user-supplied debug flags.

--- m4/cares-compilers.m4.orig	2016-01-23 22:41:55.000000000 +0000
+++ m4/cares-compilers.m4
@@ -722,13 +722,6 @@ AC_DEFUN([CARES_SET_COMPILER_DEBUG_OPTS]
       tmp_options="$flags_dbg_off"
     fi
     #
-    if test "$flags_prefer_cppflags" = "yes"; then
-      CPPFLAGS="$tmp_CPPFLAGS $tmp_options"
-      CFLAGS="$tmp_CFLAGS"
-    else
-      CPPFLAGS="$tmp_CPPFLAGS"
-      CFLAGS="$tmp_CFLAGS $tmp_options"
-    fi
     squeeze CPPFLAGS
     squeeze CFLAGS
     CARES_COMPILER_WORKS_IFELSE([
@@ -803,13 +796,6 @@ AC_DEFUN([CARES_SET_COMPILER_OPTIMIZE_OP
         AC_MSG_CHECKING([if compiler accepts optimizer disabling options])
         tmp_options="$flags_opt_off"
       fi
-      if test "$flags_prefer_cppflags" = "yes"; then
-        CPPFLAGS="$tmp_CPPFLAGS $tmp_options"
-        CFLAGS="$tmp_CFLAGS"
-      else
-        CPPFLAGS="$tmp_CPPFLAGS"
-        CFLAGS="$tmp_CFLAGS $tmp_options"
-      fi
       squeeze CPPFLAGS
       squeeze CFLAGS
       CARES_COMPILER_WORKS_IFELSE([
