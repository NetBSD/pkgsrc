$NetBSD: patch-mDNSShared_uds__daemon.c,v 1.2 2024/11/20 17:56:21 hauke Exp $

Include required for OpenBSD 5.5

MAX() defined, but not in scope, so do it here

--- mDNSShared/uds_daemon.c.orig	2024-09-24 20:38:46.000000000 +0000
+++ mDNSShared/uds_daemon.c
@@ -24,6 +24,7 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <sys/uio.h>
 #endif
 
 #include <stdlib.h>
@@ -158,6 +159,11 @@ mDNSexport DNameListElem *AutoBrowseDoma
 #endif
 #endif
 
+/* From dns_common.h */
+#ifndef MAX
+#define MAX(A, B) (((A) > (B)) ? (A) : (B))
+#endif
+
 //======================================================================================================================
 // MARK: - Log macro for request state logging.
 
