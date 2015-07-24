$NetBSD: patch-src_script.c,v 1.1 2015/07/24 10:33:27 adam Exp $

--- src/script.c.orig	2015-07-24 10:31:38.000000000 +0000
+++ src/script.c
@@ -32,6 +32,7 @@
 #include <config.h>
 #endif
 
+#include <sys/wait.h>
 #include <stdarg.h>
 
 #include "port.h"
