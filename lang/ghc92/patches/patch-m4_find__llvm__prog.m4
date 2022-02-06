$NetBSD: patch-m4_find__llvm__prog.m4,v 1.1 2022/02/06 05:36:16 pho Exp $

Abolish the bash-ism. Not upstreamed yet.

--- m4/find_llvm_prog.m4.orig	2022-01-21 02:27:51.508001986 +0000
+++ m4/find_llvm_prog.m4
@@ -15,7 +15,7 @@ AC_DEFUN([FIND_LLVM_PROG],[
     AC_CHECK_TOOLS([$1], [$PROG_VERSION_CANDIDATES $2], [])
     AS_IF([test x"$$1" != x],[
         PROG_VERSION=`$$1 --version | awk '/.*version [[0-9\.]]+/{for(i=1;i<=NF;i++){ if(\$i ~ /^[[0-9\.]]+$/){print \$i}}}'`
-        AS_IF([test x"$PROG_VERSION" == x],
+        AS_IF([test x"$PROG_VERSION" = x],
           [AC_MSG_RESULT(no)
            $1=""
            AC_MSG_NOTICE([We only support llvm $3 to $4 (no version found).])],
