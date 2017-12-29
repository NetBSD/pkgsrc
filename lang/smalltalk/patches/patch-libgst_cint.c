$NetBSD: patch-libgst_cint.c,v 1.1 2017/12/29 03:56:42 dholland Exp $

Need to declare environ these days to use it (properly this should
be made to work some other way)... this may require refinement or
ifdefs.

--- libgst/cint.c~	2013-03-23 19:56:26.000000000 +0000
+++ libgst/cint.c
@@ -396,6 +396,8 @@ my_putenv (const char *str)
   return (putenv (clone));
 }
 
+extern char **environ;
+
 static char **
 get_environ (void)
 {
