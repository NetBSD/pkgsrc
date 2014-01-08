$NetBSD: patch-src_rl__addons_renderPM___renderPM.c,v 1.1 2014/01/08 09:15:58 obache Exp $

* change label ERR to RL_ERROR_EXIT fixes breakage in solaris
  https://bitbucket.org/rptlab/reportlab/commits/88247310430c31f3e12fc3bc2a1f53be0cca30b7

--- src/rl_addons/renderPM/_renderPM.c.orig	2010-05-28 12:52:12.000000000 +0000
+++ src/rl_addons/renderPM/_renderPM.c
@@ -13,7 +13,7 @@
 #endif
 
 
-#define VERSION "1.07"
+#define VERSION "1.08"
 #define MODULE "_renderPM"
 static PyObject *moduleError;
 static PyObject *_version;
@@ -77,8 +77,8 @@ static	PyObject* parse_utf8(PyObject* se
 		first = c[i++];
 		if(first<0x80) PyList_Append(r, PyInt_FromLong(first));
 		else if(first<0xc0){
-E0:			msg = "Imvalid UTF-8 String";
-			goto ERR;
+E0:			msg = "Invalid UTF-8 String";
+			goto RL_ERROR_EXIT;
 			}
 		else if(first<0xE0){
 			second = c[i++];
@@ -93,11 +93,11 @@ E0:			msg = "Imvalid UTF-8 String";
 			}
 		else{
 			msg = "UTF-8 characters outside 16-bit range not supported";
-			goto ERR;
+			goto RL_ERROR_EXIT;
 			}
 		}
 	return r;
-ERR:
+RL_ERROR_EXIT:
     Py_DECREF(r);
 	PyErr_SetString(PyExc_ValueError,msg);
     Py_INCREF(Py_None);
