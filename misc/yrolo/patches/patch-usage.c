$NetBSD: patch-usage.c,v 1.1 2026/03/20 09:28:45 nia Exp $

Fix implicit declaration of exit(3).

--- usage.c.orig	2026-03-20 09:05:50.597207989 +0000
+++ usage.c
@@ -36,7 +36,8 @@
  */
 
 
-#include "stdio.h"
+#include <stdio.h>
+#include <stdlib.h>
 #include "defines.h"
 
 void Usage(progname)
