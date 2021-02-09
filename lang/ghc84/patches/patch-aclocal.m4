$NetBSD: patch-aclocal.m4,v 1.2 2021/02/09 12:41:32 ryoon Exp $

Fix build with autoconf-2.71. _AC_PROG_CC_C99 was removed.

Canonicalize OS name netbsd* to "netbsd".

--- aclocal.m4.orig	2018-03-25 19:22:32.000000000 +0000
+++ aclocal.m4
@@ -580,17 +580,6 @@ AC_DEFUN([FP_SET_CFLAGS_C99],
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
@@ -1981,6 +1970,9 @@ AC_DEFUN([GHC_CONVERT_OS],[
       openbsd*)
         $3="openbsd"
         ;;
+      netbsd*)
+        $3="netbsd"
+        ;;
       # As far as I'm aware, none of these have relevant variants
       freebsd|netbsd|dragonfly|hpux|linuxaout|kfreebsdgnu|freebsd2|mingw32|darwin|gnu|nextstep2|nextstep3|sunos4|ultrix|haiku)
         $3="$1"
