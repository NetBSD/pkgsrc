$NetBSD: patch-ext_odbc.c,v 1.1 2026/02/11 15:30:50 taca Exp $

* Always use char buffer for error reporting.

--- ext/odbc.c.orig	2023-09-04 09:50:32.000000000 +0000
+++ ext/odbc.c
@@ -4027,6 +4027,7 @@ dbc_getinfo(int argc, VALUE *argv, VALUE
 #else
     char buffer[513];
 #endif
+    char ebuffer[513];
 
     rb_scan_args(argc, argv, "11", &which, &vtype);
     switch (TYPE(which)) {
@@ -4072,9 +4073,9 @@ dbc_getinfo(int argc, VALUE *argv, VALUE
 			 0));
 	return Qnil;
     case 1:
-	sprintf(buffer, "Unknown info type %d for ODBC::Connection.get_info",
+	sprintf(ebuffer, "Unknown info type %d for ODBC::Connection.get_info",
 		info);
-	set_err(buffer, 1);
+	set_err(ebuffer, 1);
 	break;
     }
     if (vtype != Qnil) {
