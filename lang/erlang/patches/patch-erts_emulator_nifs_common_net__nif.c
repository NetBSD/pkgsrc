$NetBSD: patch-erts_emulator_nifs_common_net__nif.c,v 1.1 2019/08/01 11:43:00 nia Exp $

Avoid collisions with bool keyword.

--- erts/emulator/nifs/common/net_nif.c.orig	2019-07-10 16:05:15.000000000 +0000
+++ erts/emulator/nifs/common/net_nif.c
@@ -214,6 +214,7 @@
 
 #define NDBG( proto ) ESOCK_DBG_PRINTF( data.debug , proto )
 
+#undef bool
 
 typedef struct {
     BOOLEAN_T debug;
