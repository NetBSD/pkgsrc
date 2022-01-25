$NetBSD: patch-m4_python.m4,v 1.7 2022/01/25 18:57:29 wiz Exp $

Support python 3.10.
http://debbugs.gnu.org/cgi/bugreport.cgi?bug=53530

--- m4/python.m4.orig	2021-10-04 02:51:12.000000000 +0000
+++ m4/python.m4
@@ -38,6 +38,7 @@ AC_DEFUN([AM_PATH_PYTHON],
   dnl supported. (2.0 was released on October 16, 2000).
   m4_define_default([_AM_PYTHON_INTERPRETER_LIST],
 [python python2 python3 dnl
+ python3.10 dnl
  python3.9 python3.8 python3.7 python3.6 python3.5 python3.4 python3.3 dnl
  python3.2 python3.1 python3.0 dnl
  python2.7 python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 dnl
