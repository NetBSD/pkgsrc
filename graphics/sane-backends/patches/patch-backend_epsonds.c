$NetBSD: patch-backend_epsonds.c,v 1.1 2018/02/25 21:22:07 wiz Exp $

Add header for struct timeval.

--- backend/epsonds.c.orig	2017-05-15 01:19:11.000000000 +0000
+++ backend/epsonds.c
@@ -41,6 +41,7 @@
 #include "sane/config.h"
 
 #include <ctype.h>
+#include <sys/time.h>
 #include <unistd.h>
 
 #include "sane/saneopts.h"
