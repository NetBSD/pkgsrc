$NetBSD: patch-src_auth_pool__hba.c,v 1.1 2021/04/28 09:18:55 wiz Exp $

--- src/auth/pool_hba.c.orig	2021-04-24 00:32:29.786972517 +0300
+++ src/auth/pool_hba.c	2021-04-24 00:33:47.296429745 +0300
@@ -30,9 +30,9 @@
 #include <errno.h>
 #include <netdb.h>
 
-#ifdef __FreeBSD__
+#include <sys/types.h>
 #include <netinet/in.h>
-#endif
+#include <netinet6/in6.h>
 
 #include "pool.h"
 #include "auth/pool_hba.h"
