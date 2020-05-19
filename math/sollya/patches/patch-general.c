$NetBSD: patch-general.c,v 1.1 2020/05/19 14:45:21 riastradh Exp $

Get declarations for gettimeofday and clock_gettime on NetBSD.

--- general.c.orig	2018-08-27 08:32:07.000000000 +0000
+++ general.c
@@ -73,7 +73,7 @@
 #include "signalhandling.h"
 
 #define _POSIX_SOURCE
-#define _POSIX_C_SOURCE 199309L
+#define _POSIX_C_SOURCE 200112L
 
 #include <sys/types.h>
 #include <gmp.h>
