$NetBSD: patch-src_main.c,v 1.1 2025/02/10 13:13:27 wiz Exp $

Do not define variables in a header file.

--- src/main.c.orig	2018-01-06 22:53:49.000000000 +0000
+++ src/main.c
@@ -33,6 +33,10 @@
 #include "pkg_config.h"
 #endif
 
+int nbactions;
+int nbdone;
+int nbtodl;
+
 #include <sys/param.h>
 
 #include <sys/stat.h>
