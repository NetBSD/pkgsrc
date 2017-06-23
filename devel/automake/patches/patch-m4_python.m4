$NetBSD: patch-m4_python.m4,v 1.4 2017/06/23 12:52:56 wiz Exp $

AM_PATH_PYTHON: look for python3.6 binary as well.
http://debbugs.gnu.org/cgi/bugreport.cgi?bug=27458

--- m4/python.m4.orig	2017-06-16 21:01:05.000000000 +0000
+++ m4/python.m4
@@ -38,7 +38,7 @@ AC_DEFUN([AM_PATH_PYTHON],
   dnl supported. (2.0 was released on October 16, 2000).
   dnl FIXME: Remove the need to hard-code Python versions here.
   m4_define_default([_AM_PYTHON_INTERPRETER_LIST],
-[python python2 python3 python3.5 python3.4 python3.3 python3.2 python3.1 python3.0 python2.7 dnl
+[python python2 python3 python3.6 python3.5 python3.4 python3.3 python3.2 python3.1 python3.0 python2.7 dnl
  python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 python2.0])
 
   AC_ARG_VAR([PYTHON], [the Python interpreter])
