$NetBSD: patch-lib_smi-data.c,v 1.1 2025/04/28 19:34:48 tnn Exp $

Replace K&R prototype.

--- lib/smi-data.c.orig	2025-04-28 19:29:01.830808697 +0000
+++ lib/smi-data.c
@@ -39,12 +39,12 @@
 
 #ifdef BACKEND_SMI
 #include "scanner-smi.h"
-extern int smiparse();
+extern int smiparse(struct Parser *);
 #endif
 
 #ifdef BACKEND_SMING
 #include "scanner-sming.h"
-extern int smingparse();
+extern int smingparse(struct Parser *);
 #endif
 
 #define stringKind(kind) ( \
