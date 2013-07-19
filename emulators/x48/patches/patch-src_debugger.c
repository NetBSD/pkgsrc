$NetBSD: patch-src_debugger.c,v 1.1 2013/07/19 12:51:11 joerg Exp $

--- src/debugger.c.orig	2013-07-19 10:21:21.000000000 +0000
+++ src/debugger.c
@@ -1528,7 +1528,7 @@ struct se {
   struct se *se_next;
 };
 
-char *
+void
 #ifdef __FunctionProto__
 get_stack (void)
 #else
