$NetBSD: patch-apps_app__macro.c,v 1.1 2024/07/08 05:03:01 jnemeth Exp $

--- apps/app_macro.c.orig	2024-06-24 04:57:51.676510464 +0000
+++ apps/app_macro.c
@@ -26,7 +26,6 @@
  */
 
 /*** MODULEINFO
-	<defaultenabled>no</defaultenabled>
 	<support_level>deprecated</support_level>
 	<replacement>app_stack (GoSub)</replacement>
 	<deprecated_in>16</deprecated_in>
