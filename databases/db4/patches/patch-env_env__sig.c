$NetBSD: patch-env_env__sig.c,v 1.1 2014/07/18 11:20:39 ryoon Exp $

--- env/env_sig.c.orig	2010-04-12 20:25:33.000000000 +0000
+++ env/env_sig.c
@@ -5,4 +5,8 @@
  */
 
+#if !defined(u_int64_t)
+typedef unsigned long long u_int64_t;
+#endif
+
 #include "db_config.h"
 
