$NetBSD: patch-config_amanda_config_flags.m4,v 1.1 2018/11/23 22:33:13 spz Exp $

fix amanda gcc flags checking

--- ./config/amanda/flags.m4.orig	2016-02-09 22:52:50.000000000 +0000
+++ ./config/amanda/flags.m4
@@ -351,7 +351,7 @@ AC_DEFUN([AMANDA_TEST_GCC_FLAG],
     AC_MSG_CHECKING(for gcc flag $1)
     if test "x$GCC" = "xyes"; then
 	changequote(,)dnl
-	($CC --help={target,optimizers,warnings,undocumented,params,c} 2>&1 || 
+	($CC --help=target --help=optimizers --help=warnings --help=undocumented --help=params --help=c 2>&1 || 
            $CC -v --help 2>&1) | 
          $EGREP -- '[^0-9A-Za-z]$1[^0-9A-Za-z]' 2>&1 > /dev/null
 	changequote([,])dnl
