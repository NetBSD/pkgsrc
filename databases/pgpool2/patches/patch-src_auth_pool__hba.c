$NetBSD: patch-src_auth_pool__hba.c,v 1.2 2022/05/18 11:20:35 adam Exp $

--- src/auth/pool_hba.c.orig	2022-02-17 01:45:01.000000000 +0000
+++ src/auth/pool_hba.c
@@ -30,9 +30,8 @@
 #include <errno.h>
 #include <netdb.h>
 
-#ifdef __FreeBSD__
+#include <sys/types.h>
 #include <netinet/in.h>
-#endif
 
 #include "pool.h"
 #include "auth/pool_hba.h"
