$NetBSD: patch-acinclude.m4,v 1.1 2024/02/25 12:09:21 schmonz Exp $

Fix autoreconf warnings.

--- acinclude.m4.orig	2024-02-21 15:45:31.387684310 +0000
+++ acinclude.m4
@@ -1,5 +1,5 @@
 dnl TRY_CXX_FLAG(FLAG,[ACTION-IF-FOUND[,ACTION-IF-NOT-FOUND]])
-AC_DEFUN(TRY_CXX_FLAG,
+AC_DEFUN([TRY_CXX_FLAG],
 [echo >conftest.cc
 if ${CXX-g++} ${CXXFLAGS} -c [$1] conftest.cc >/dev/null 2>&1; then
   ifelse([$2], , :, [rm -f conftest*
@@ -10,7 +10,7 @@ else
 fi
 rm -f conftest*])
 
-AC_DEFUN(CXX_NO_RTTI,
+AC_DEFUN([CXX_NO_RTTI],
 [AC_CACHE_CHECK(whether ${CXX-g++} accepts -fno-rtti,
 	local_cv_flag_NO_RTTI,
 	TRY_CXX_FLAG(-fno-rtti,
@@ -19,7 +19,7 @@ AC_DEFUN(CXX_NO_RTTI,
 test "$local_cv_flag_NO_RTTI" = yes && CXXFLAGS="$CXXFLAGS -fno-rtti"
 ])
 
-AC_DEFUN(CXX_NO_EXCEPTIONS,
+AC_DEFUN([CXX_NO_EXCEPTIONS],
 [AC_CACHE_CHECK(whether ${CXX-g++} accepts -fno-exceptions,
 	local_cv_flag_NO_EXCEPTIONS,
 	TRY_CXX_FLAG(-fno-exceptions,
