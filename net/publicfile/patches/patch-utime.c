$NetBSD: patch-utime.c,v 1.2 2023/11/16 22:55:37 schmonz Exp $

Add missing include.

--- utime.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ utime.c
@@ -1,5 +1,6 @@
 #include <sys/types.h>
 #include <sys/time.h>
+#include <utime.h>
 #include "scan.h"
 #include "exit.h"
 
