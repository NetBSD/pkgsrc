$NetBSD: patch-plugins_dfcdrom_cdr.c,v 1.1 2020/09/29 12:23:03 nia Exp $

Make this more generic.

--- plugins/dfcdrom/cdr.c.orig	2019-03-06 11:37:17.000000000 +0000
+++ plugins/dfcdrom/cdr.c
@@ -20,7 +20,7 @@
  */
 
 #include "cdr.h"
-#if defined(__linux__)
+#ifndef _MACOSX
 #include <sys/types.h>
 #include <sys/wait.h>
 #endif 
