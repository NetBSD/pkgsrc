$NetBSD: patch-m4_fptools.m4,v 1.1 2022/01/18 02:22:50 pho Exp $

Hunk #0:
  Mark the stack as non-executable on NetBSD/aarch64.
  https://gitlab.haskell.org/ghc/ghc/-/merge_requests/5805

Hunk #1
  Abolish the bash-ism. Not upstreamed. I'm honestly tired of upstreaming this
  specific kind of patch because this is never the first time they made this
  mistake. (pho@)

--- m4/fptools.m4.orig	2021-12-25 13:13:59.000000000 +0000
+++ m4/fptools.m4
@@ -761,6 +761,10 @@ AC_DEFUN([FPTOOLS_SET_C_LD_FLAGS],
         $3="$$3 -Wl,-z,noexecstack"
         $4="$$4 -z noexecstack"
         ;;
+    aarch64*netbsd*)
+        $3="$$3 -Wl,-z,noexecstack"
+        $4="$$4 -z noexecstack"
+        ;;
 
     powerpc-ibm-aix*)
         # We need `-D_THREAD_SAFE` to unlock the thread-local `errno`.
@@ -2242,7 +2246,7 @@ AC_DEFUN([FIND_LLVM_PROG],[
     AC_CHECK_TOOLS([$1], [$PROG_VERSION_CANDIDATES $2], [])
     AS_IF([test x"$$1" != x],[
         PROG_VERSION=`$$1 --version | awk '/.*version [[0-9\.]]+/{for(i=1;i<=NF;i++){ if(\$i ~ /^[[0-9\.]]+$/){print \$i}}}'`
-        AS_IF([test x"$PROG_VERSION" == x],
+        AS_IF([test x"$PROG_VERSION" = x],
           [AC_MSG_RESULT(no)
            $1=""
            AC_MSG_NOTICE([We only support llvm $3 to $4 (no version found).])],
