$NetBSD: patch-src_update.c,v 1.2 2012/08/09 23:25:05 marino Exp $

--- src/update.c.orig	2012-06-24 16:52:03.000000000 +0000
+++ src/update.c
@@ -44,6 +44,10 @@
 #include "environment.h"
 #include "utils.h"
 
+#if defined(__NetBSD__) || defined(__DragonFly__)
+#include <netinet/in.h>
+#endif
+
 #ifdef WIN32
 /* TODO: use Winsock for WIN32 */
 #else
