$NetBSD: patch-utime.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- utime.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ utime.c
@@ -1,5 +1,6 @@
 #include <sys/types.h>
 #include <sys/time.h>
+#include <utime.h>
 #include "scan.h"
 #include "exit.h"
 
