$NetBSD: patch-lib_BlocksRuntime_config.h,v 1.1 2018/06/02 19:11:01 joerg Exp $

--- lib/BlocksRuntime/config.h.orig	2018-05-07 16:23:52.356787945 +0000
+++ lib/BlocksRuntime/config.h
@@ -0,0 +1,2 @@
+#define HAVE_SYNC_BOOL_COMPARE_AND_SWAP_INT
+#define HAVE_SYNC_BOOL_COMPARE_AND_SWAP_LONG
