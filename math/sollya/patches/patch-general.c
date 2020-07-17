$NetBSD: patch-general.c,v 1.2 2020/07/17 17:30:13 riastradh Exp $

Get declarations for gettimeofday and clock_gettime on NetBSD.

https://lists.gforge.inria.fr/pipermail/sollya-devl/2020-July/000019.html

--- general.c.orig	2018-08-27 08:32:07.000000000 +0000
+++ general.c
@@ -73,7 +73,7 @@
 #include "signalhandling.h"
 
 #define _POSIX_SOURCE
-#define _POSIX_C_SOURCE 199309L
+#define _POSIX_C_SOURCE 200112L
 
 #include <sys/types.h>
 #include <gmp.h>
