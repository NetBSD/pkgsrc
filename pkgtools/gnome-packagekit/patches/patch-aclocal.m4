$NetBSD: patch-aclocal.m4,v 1.1 2012/12/15 09:36:21 marino Exp $

* Disable -Werror for these reasons
  - Numerous g_thread_init deprecated errors
  - Numerous set-but-not-used error (gcc 4.6+)

--- aclocal.m4.orig	2008-12-09 08:25:48.000000000 +0000
+++ aclocal.m4
@@ -546,9 +546,6 @@ AC_DEFUN([GNOME_COMPILE_WARNINGS],[
 		unset SAVE_CFLAGS
 	done
 	unset option
-	if test "$enable_compile_warnings" = "error" ; then
-	    warning_flags="$warning_flags -Werror"
-	fi
 	;;
     *)
 	AC_MSG_ERROR(Unknown argument '$enable_compile_warnings' to --enable-compile-warnings)
