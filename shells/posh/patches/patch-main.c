$NetBSD: patch-main.c,v 1.1 2013/06/11 21:43:13 mef Exp $

Avoid getting following warning, 
  main.c: In function 'main':
  main.c:206:15: warning: assignment makes pointer from integer without a cast
and segmentation faulting just after invocation on NetBSD/amd64 6.1.

--- main.c.orig	2004-06-09 00:51:50.000000000 +0900
+++ main.c	2013-06-12 00:40:13.000000000 +0900
@@ -7,6 +7,7 @@
 #include "sh.h"
 #include "ksh_stat.h"
 #include "ksh_time.h"
+#include "src/compat.h"
 
 extern char **environ;
 
