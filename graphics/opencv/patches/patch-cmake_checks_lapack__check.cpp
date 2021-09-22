$NetBSD: patch-cmake_checks_lapack__check.cpp,v 1.1 2021/09/22 13:40:41 nia Exp $

https://bugs.gentoo.org/800539
https://github.com/opencv/opencv/issues/19846

--- cmake/checks/lapack_check.cpp.orig	2019-12-19 15:16:47.000000000 +0000
+++ cmake/checks/lapack_check.cpp
@@ -2,9 +2,9 @@
 #include "opencv_lapack.h"
 
 static char* check_fn1 = (char*)sgesv_;
-static char* check_fn2 = (char*)sposv_;
-static char* check_fn3 = (char*)spotrf_;
-static char* check_fn4 = (char*)sgesdd_;
+static char* check_fn2 = (char*)LAPACK_sposv_;
+static char* check_fn3 = (char*)LAPACK_spotrf_;
+static char* check_fn4 = (char*)LAPACK_sgesdd_;
 
 int main(int argc, char* argv[])
 {
