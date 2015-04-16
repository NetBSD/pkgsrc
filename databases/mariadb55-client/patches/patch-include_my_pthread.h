$NetBSD: patch-include_my_pthread.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- include/my_pthread.h.orig	2015-02-13 12:07:01.000000000 +0000
+++ include/my_pthread.h
@@ -21,6 +21,8 @@
 
 #include "my_global.h"                          /* myf */
 
+#include <signal.h>
+
 #ifndef ETIME
 #define ETIME ETIMEDOUT				/* For FreeBSD */
 #endif
