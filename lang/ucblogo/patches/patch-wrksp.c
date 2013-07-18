$NetBSD: patch-wrksp.c,v 1.1 2013/07/18 12:05:09 joerg Exp $

--- wrksp.c.orig	2013-07-17 14:30:28.000000000 +0000
+++ wrksp.c
@@ -30,6 +30,7 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#include <sys/wait.h>
 
 #ifdef ibm
 #include "process.h"
