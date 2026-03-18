$NetBSD: patch-strutil.c,v 1.1 2026/03/18 17:02:37 nia Exp $

Fix implicit function declarations.

--- strutil.c.orig	2026-03-18 16:35:25.970568085 +0000
+++ strutil.c
@@ -7,6 +7,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sysexits.h>
 #include <memory.h>
