$NetBSD: patch-tools_gimptool.c,v 1.1 2013/09/10 14:19:46 joerg Exp $

--- tools/gimptool.c.orig	2013-09-10 10:01:04.000000000 +0000
+++ tools/gimptool.c
@@ -263,7 +263,7 @@ find_out_env_flags (void)
   else
     env_cc = CC;
 
-  if (g_ascii_strncasecmp (env_cc, "cl", 2) == 0)
+  if (g_ascii_strncasecmp (env_cc, "cl", 2) == 0 && !g_ascii_strncasecmp (env_cc, "clang", 5) == 0)
     msvc_syntax = TRUE;
 
   if ((p = getenv ("CFLAGS")) != NULL)
