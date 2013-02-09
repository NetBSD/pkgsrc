$NetBSD: patch-drivers_netjack_netjack__packet.c,v 1.2 2013/02/09 19:59:45 ryoon Exp $

--- drivers/netjack/netjack_packet.c.orig	2011-06-08 23:54:48.000000000 +0000
+++ drivers/netjack/netjack_packet.c
@@ -44,6 +44,10 @@
 #include <errno.h>
 #include <stdarg.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include <jack/types.h>
 
 // for jack_error in jack1
