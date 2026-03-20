$NetBSD: patch-apdutils.c,v 1.1 2026/03/20 11:04:14 nia Exp $

SunOS requires alloca.h

--- apdutils.c.orig	2003-09-01 00:22:06.000000000 +0000
+++ apdutils.c
@@ -3,4 +3,7 @@
  */
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <string.h>
