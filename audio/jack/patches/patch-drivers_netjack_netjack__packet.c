$NetBSD: patch-drivers_netjack_netjack__packet.c,v 1.1 2012/01/11 17:51:21 hans Exp $

--- drivers/netjack/netjack_packet.c.orig	2008-11-11 23:36:40.000000000 +0100
+++ drivers/netjack/netjack_packet.c	2011-12-30 03:30:24.997459515 +0100
@@ -35,6 +35,10 @@
 #include <errno.h>
 #include <stdarg.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include <jack/types.h>
 #include <jack/engine.h>
 
