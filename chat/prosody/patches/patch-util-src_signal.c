$NetBSD: patch-util-src_signal.c,v 1.1 2020/01/23 18:26:15 gdt Exp $

Include <sys/param.h> when on UNIX

--- util-src/signal.c.orig	2019-08-31 14:08:45.000000000 +0000
+++ util-src/signal.c
@@ -33,6 +33,10 @@
 #include <signal.h>
 #include <stdlib.h>
 
+#ifdef __unix__
+#include <sys/param.h>
+#endif
+
 #include "lua.h"
 #include "lauxlib.h"
 
