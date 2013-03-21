$NetBSD: patch-lib_api.c,v 1.1 2013/03/21 06:49:12 sbd Exp $

Make sure that bt_addr_t is defined.

--- lib/api.c.orig	2013-03-02 14:25:42.000000000 +0000
+++ lib/api.c
@@ -64,6 +64,10 @@
 
 #include "obex_incl.h"
 
+#if !defined(bt_addr_t)
+#define bt_addr_t void
+#endif
+
 /**
 	Initialize OBEX.
 	\param transport Which transport to use. The following transports are available :
