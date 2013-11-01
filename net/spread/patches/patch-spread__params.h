$NetBSD: patch-spread__params.h,v 1.1 2013/11/01 13:26:53 jperkin Exp $

Make sure the runtime dir and user/group bits are passed on.

--- spread_params.h.orig	2004-10-05 14:42:14.000000000 +0000
+++ spread_params.h
@@ -43,13 +43,13 @@
 #define		DEFAULT_SPREAD_PORT	4803
 
 #ifndef SP_RUNTIME_DIR
-#define         SP_RUNTIME_DIR          "/var/run/spread"
+#define         SP_RUNTIME_DIR          "@RUNTIME_DIR@"
 #endif
 #ifndef SP_GROUP
-#define         SP_GROUP                "spread"
+#define         SP_GROUP                "@SPREAD_GROUP@"
 #endif
 #ifndef SP_USER
-#define         SP_USER                 "spread"
+#define         SP_USER                 "@SPREAD_USER@"
 #endif
 
 #define		MAX_PROC_NAME		 20     /* including the null, so actually max 19, look for it if changed */
