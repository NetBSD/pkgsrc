$NetBSD: patch-Modules_posixmodule.c,v 1.2 2015/04/24 03:01:36 rodent Exp $

--- Modules/posixmodule.c.orig	2014-12-10 15:59:55.000000000 +0000
+++ Modules/posixmodule.c
@@ -317,6 +317,10 @@ extern int lstat(const char *, struct st
 #define PARSE_PID "i"
 #define PyLong_FromPid PyInt_FromLong
 #define PyLong_AsPid PyInt_AsLong
+#elif SIZEOF_PID_T == SIZEOF_SHORT
+#define PARSE_PID "i"
+#define PyLong_FromPid PyInt_FromLong
+#define PyLong_AsPid PyInt_AsLong
 #elif SIZEOF_PID_T == SIZEOF_LONG
 #define PARSE_PID "l"
 #define PyLong_FromPid PyInt_FromLong
