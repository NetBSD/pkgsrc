$NetBSD: patch-itex2MML.y,v 1.1 2013/09/01 15:39:54 wiz Exp $

Fix build with bison-3.0

--- itex2MML.y.orig	2007-05-06 17:20:44.000000000 +0000
+++ itex2MML.y
@@ -2,6 +2,8 @@
  *   itex2MML.y last modified 5/6/2007
  */
 
+%parse-param {char **ret_str}
+
 %{
 #include <stdio.h>
 #include <string.h>
@@ -27,7 +29,7 @@
 
  void (*itex2MML_error) (const char * msg) = itex2MML_default_error;
 
- static void yyerror (char * s)
+ static void yyerror (char **ret_str, char * s)
    {
      char * msg = itex2MML_copy3 (s, " at token ", yytext);
      if (itex2MML_error)
