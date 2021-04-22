$NetBSD: patch-aclocal.m4,v 1.2 2021/04/22 18:15:01 pho Exp $

Remove _AC_PROG_CC_C99 macro that is removed in autoconf-2.71 to fix
build failure.

--- aclocal.m4.orig	2021-01-26 14:49:54.000000000 +0000
+++ aclocal.m4
@@ -656,17 +656,6 @@ AC_DEFUN([FP_SET_CFLAGS_C99],
     CC="$$1"
     CFLAGS="$$2"
     CPPFLAGS="$$3"
-    unset ac_cv_prog_cc_c99
-    dnl perform detection
-    _AC_PROG_CC_C99
-    fp_cc_c99="$ac_cv_prog_cc_c99"
-    case "x$ac_cv_prog_cc_c99" in
-      x)   ;; # noop
-      xno) AC_MSG_ERROR([C99-compatible compiler needed]) ;;
-      *)   $2="$$2 $ac_cv_prog_cc_c99"
-           $3="$$3 $ac_cv_prog_cc_c99"
-           ;;
-    esac
     dnl restore saved state
     FP_COPY_SHELLVAR([fp_save_CC],[CC])
     FP_COPY_SHELLVAR([fp_save_CFLAGS],[CFLAGS])
