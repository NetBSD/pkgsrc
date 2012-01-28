$NetBSD: patch-aclocal.m4,v 1.1 2012/01/28 04:37:36 sbd Exp $

--- aclocal.m4.orig	2005-07-24 07:33:36.000000000 +0000
+++ aclocal.m4
@@ -13,8 +13,7 @@ AC_MSG_CHECKING(for __attribute__)
 AC_CACHE_VAL(ac_cv___attribute__, [
 AC_TRY_COMPILE([
 #include <stdlib.h>
-],
-[
+
 static void foo(void) __attribute__ ((noreturn));
 
 static void
@@ -23,6 +22,7 @@ foo(void)
   exit(1);
 }
 ],
+[],
 ac_cv___attribute__=yes,
 ac_cv___attribute__=no)])
 if test "$ac_cv___attribute__" = "yes"; then
