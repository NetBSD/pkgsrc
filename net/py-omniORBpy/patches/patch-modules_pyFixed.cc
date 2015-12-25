$NetBSD: patch-modules_pyFixed.cc,v 1.1 2015/12/25 20:09:28 joerg Exp $

--- modules/pyFixed.cc.orig	2015-12-25 19:52:09.000000000 +0000
+++ modules/pyFixed.cc
@@ -99,7 +99,7 @@ omniPy::newFixedObject(PyObject* self, P
 	return omniPy::newFixedObject(f);
       }
       else if (PyInt_Check(pyv)) {
-	long l = PyInt_AsLong(pyv);
+	CORBA::LongLong l = PyInt_AsLong(pyv);
 	CORBA::Fixed f(l);
 	return omniPy::newFixedObject(f);
       }
@@ -138,7 +138,7 @@ omniPy::newFixedObject(PyObject* self, P
 	// an integer value, then hack the scale to be correct.
 
 	if (PyInt_Check(pyv)) {
-	  long l = PyInt_AsLong(pyv);
+	  CORBA::LongLong l = PyInt_AsLong(pyv);
 	  CORBA::Fixed f(l);
 	  f.PR_changeScale(scale);
 	  f.PR_setLimits(digits, scale);
@@ -368,7 +368,7 @@ extern "C" {
   fixed_coerce(PyObject** pv, PyObject** pw)
   {
     if (PyInt_Check(*pw)) {
-      long l = PyInt_AsLong(*pw);
+      CORBA::LongLong l = PyInt_AsLong(*pw);
       CORBA::Fixed f(l);
       *pw = omniPy::newFixedObject(f);
       Py_INCREF(*pv);
