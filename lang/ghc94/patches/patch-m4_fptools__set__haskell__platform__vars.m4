$NetBSD: patch-m4_fptools__set__haskell__platform__vars.m4,v 1.1 2023/01/21 04:49:25 pho Exp $

Pretend the toolchain doesn't support .note.GNU-stack on NetBSD. This is a
temporary workaround and shouldn't live forever. See:
https://mail-index.netbsd.org/tech-toolchain/2023/01/15/msg004188.html

--- m4/fptools_set_haskell_platform_vars.m4.orig	2023-01-15 14:19:38.638967614 +0000
+++ m4/fptools_set_haskell_platform_vars.m4
@@ -180,6 +180,11 @@ AC_DEFUN([GHC_IDENT_DIRECTIVE],
 # so we empty CFLAGS while running this test
 AC_DEFUN([GHC_GNU_NONEXEC_STACK],
 [
+    case $TargetOS in
+      netbsd)
+        TargetHasGnuNonexecStack=NO;;
+      *)
+
     CFLAGS2="$CFLAGS"
     CFLAGS=
     case $TargetArch in
@@ -206,6 +211,8 @@ AC_DEFUN([GHC_GNU_NONEXEC_STACK],
         [AC_MSG_RESULT(no)
          TargetHasGnuNonexecStack=NO])
     CFLAGS="$CFLAGS2"
+
+    esac
 ])
 
 # FPTOOLS_SET_HASKELL_PLATFORM_VARS
