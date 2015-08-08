$NetBSD: patch-m4_python.m4,v 1.1 2015/08/08 20:42:45 wiz Exp $

AM_PATH_PYTHON: look for python3.4 binary as well.
http://debbugs.gnu.org/cgi/bugreport.cgi?bug=21219

--- m4/python.m4.orig	2014-12-30 13:49:41.000000000 +0000
+++ m4/python.m4
@@ -37,7 +37,7 @@ AC_DEFUN([AM_PATH_PYTHON],
   dnl Find a Python interpreter.  Python versions prior to 2.0 are not
   dnl supported. (2.0 was released on October 16, 2000).
   m4_define_default([_AM_PYTHON_INTERPRETER_LIST],
-[python python2 python3 python3.3 python3.2 python3.1 python3.0 python2.7 dnl
+[python python2 python3 python3.4 python3.3 python3.2 python3.1 python3.0 python2.7 dnl
  python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 python2.0])
 
   AC_ARG_VAR([PYTHON], [the Python interpreter])
