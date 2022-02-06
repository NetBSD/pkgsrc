$NetBSD: patch-m4_fptools__set__c__ld__flags.m4,v 1.1 2022/02/06 05:36:16 pho Exp $

Mark the stack as non-executable on NetBSD/aarch64.
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/5805

--- m4/fptools_set_c_ld_flags.m4.orig	2022-01-21 02:26:18.260679308 +0000
+++ m4/fptools_set_c_ld_flags.m4
@@ -79,6 +79,10 @@ AC_DEFUN([FPTOOLS_SET_C_LD_FLAGS],
         $3="$$3 -Wl,-z,noexecstack"
         $4="$$4 -z noexecstack"
         ;;
+    aarch64*netbsd*)
+        $3="$$3 -Wl,-z,noexecstack"
+        $4="$$4 -z noexecstack"
+        ;;
 
     powerpc-ibm-aix*)
         # We need `-D_THREAD_SAFE` to unlock the thread-local `errno`.
