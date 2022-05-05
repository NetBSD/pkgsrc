$NetBSD: patch-common.h,v 1.1 2022/05/05 14:31:35 nia Exp $

Uses bool - need to include stdbool.h.

--- common.h.orig	2019-02-24 14:53:23.000000000 +0000
+++ common.h
@@ -90,6 +90,7 @@
 #include <semaphore.h>
 #include <signal.h>
 #include <stdarg.h>
+#include <stdbool.h>
 #include <stdio.h>
 #include <syslog.h>
 
