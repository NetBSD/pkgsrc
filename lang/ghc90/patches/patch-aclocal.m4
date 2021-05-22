$NetBSD: patch-aclocal.m4,v 1.5 2021/05/22 09:10:36 pho Exp $

Hunk #0:
  Remove _AC_PROG_CC_C99 macro that is removed in autoconf-2.71 to fix
  build failure.

  Already fixed in the upstream:
  https://gitlab.haskell.org/ghc/ghc/-/merge_requests/4987

Hunk #1:
  Mark the stack as non-executable on NetBSD/aarch64.
  https://gitlab.haskell.org/ghc/ghc/-/merge_requests/5805

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
@@ -759,6 +748,10 @@ AC_DEFUN([FPTOOLS_SET_C_LD_FLAGS],
         $3="$$3 -Wl,-z,noexecstack"
         $4="$$4 -z noexecstack"
         ;;
+    aarch64*netbsd*)
+        $3="$$3 -Wl,-z,noexecstack"
+	$4="$$4 -z noexecstack"
+	;;
 
     powerpc-ibm-aix*)
         # We need `-D_THREAD_SAFE` to unlock the thread-local `errno`.
