$NetBSD: patch-src__c_base.c,v 1.1 2026/05/26 02:13:09 gutteridge Exp $

Fix ctype(3) usage.

--- src_c/base.c.orig	2024-09-29 12:15:28.003111800 +0000
+++ src_c/base.c
@@ -2152,7 +2152,7 @@ _pg_typestr_as_format(PyObject *sp, char *format, Py_s
             }
             if (typestr[1] == 'i') {
                 /* This leaves 'x' uneffected. */
-                *fchar_p = tolower(*fchar_p);
+                *fchar_p = tolower((unsigned char)*fchar_p);
             }
             break;
         case 'f':
