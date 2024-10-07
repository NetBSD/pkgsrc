$NetBSD: patch-src_platform.c,v 1.1 2024/10/07 16:35:59 rhialto Exp $

- Use the default library location

--- src/platform.c.orig	2024-10-03 14:02:09.161143375 +0000
+++ src/platform.c
@@ -36,7 +36,7 @@
 #include "dynabuf.h"
 
 // path of library tree, taken from env var
-char	*platform_lib_prefix	= NULL;
+char	*platform_lib_prefix	= DEFAULT_ACME_LIB;
 
 // function to setup pointer above
 void platform_read_env_var(void)
