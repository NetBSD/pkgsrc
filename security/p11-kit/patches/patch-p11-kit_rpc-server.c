$NetBSD: patch-p11-kit_rpc-server.c,v 1.1 2024/07/09 16:55:12 nia Exp $

limits.h is need for ULONG_MAX and friends.
Helps building on illumos.

--- p11-kit/rpc-server.c.orig	2024-07-09 16:46:39.441314274 +0000
+++ p11-kit/rpc-server.c
@@ -57,6 +57,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>
 #include <unistd.h>
 
 #ifdef ENABLE_NLS
