$NetBSD: patch-Variables.h,v 1.2 2015/12/29 23:34:43 dholland Exp $

Update C++ dialect.

--- Variables.h.orig	2015-06-09 23:15:06.000000000 +0000
+++ Variables.h
@@ -34,7 +34,7 @@ struct variable
   union {
     char *string;
     double floatval; 
-    array *arr;
+    ::array *arr;
   } value;
 };
 
