$NetBSD: patch-build_autoconf_compiler-opts.m4,v 1.1 2016/02/14 07:30:54 ryoon Exp $

It's true Clang is required if we use the cocoa toolkit, but we don't
do that anyway. GCC is perfectly working as long as we use cairo-gtk2.

--- build/autoconf/compiler-opts.m4.orig	2014-05-06 22:55:14.000000000 +0000
+++ build/autoconf/compiler-opts.m4
@@ -53,14 +53,6 @@ case "$target" in
     if test -z "$CXX"; then
         MOZ_PATH_PROGS(CXX, clang++)
     fi
-    IS_GCC=$($CC -v 2>&1 | grep gcc)
-    if test -n "$IS_GCC"
-    then
-      echo gcc is known to be broken on OS X, please use clang.
-      echo see http://developer.mozilla.org/en-US/docs/Developer_Guide/Build_Instructions/Mac_OS_X_Prerequisites
-      echo for more information.
-      exit 1
-    fi
     ;;
 esac
 fi
