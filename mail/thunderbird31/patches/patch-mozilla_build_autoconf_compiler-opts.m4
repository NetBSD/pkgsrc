$NetBSD: patch-mozilla_build_autoconf_compiler-opts.m4,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/build/autoconf/compiler-opts.m4.orig	2014-07-18 00:05:10.000000000 +0000
+++ mozilla/build/autoconf/compiler-opts.m4
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
