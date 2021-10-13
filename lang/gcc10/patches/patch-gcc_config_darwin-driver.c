$NetBSD: patch-gcc_config_darwin-driver.c,v 1.1 2021/10/13 12:38:52 adam Exp $

Allow macOS 12.

--- gcc/config/darwin-driver.c.orig	2021-10-13 11:50:13.000000000 +0000
+++ gcc/config/darwin-driver.c
@@ -64,7 +64,7 @@ validate_macosx_version_min (const char 
 
   major = strtoul (version_str, &end, 10);
 
-  if (major < 10 || major > 11 ) /* MacOS 10 and 11 are known. */
+  if (major < 10 || major > 12 ) /* MacOS 10 and 11 and 12 are known. */
     return NULL;
 
   /* Skip a separating period, if there's one.  */
