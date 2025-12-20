$NetBSD: patch-src_dial.c,v 1.1 2025/12/20 12:15:46 nia Exp $

Fix implicit declaration of alloca(3).

--- src/dial.c.orig	2025-12-20 11:50:36.322648757 +0000
+++ src/dial.c
@@ -31,8 +31,13 @@
 #endif
 
 #include <stdint.h>
+#include <stdlib.h>
 #include <limits.h>
 #include <arpa/inet.h>
+
+#if defined(__linux__) || defined(__sun)
+#include <alloca.h>
+#endif
 
 #include "port.h"
 #include "minicom.h"
