$NetBSD: patch-config.m4,v 1.1 2021/03/07 12:58:29 taca Exp $

Fix portability use of test(1).

--- config.m4.orig	2019-03-13 19:59:39.000000000 +0000
+++ config.m4
@@ -98,7 +98,7 @@ dnl Check for igbinary
   fi
 
   AC_CHECK_PROG([GIT], [git], [yes], [no])
-  if test "$GIT" == "yes" && test -d "$srcdir/.git"; then
+  if test "$GIT" = "yes" && test -d "$srcdir/.git"; then
     AC_DEFINE_UNQUOTED(GIT_REVISION, ["$(git log -1 --format=%H)"], [ ])
   fi
 
