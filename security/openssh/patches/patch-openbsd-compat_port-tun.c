$NetBSD: patch-openbsd-compat_port-tun.c,v 1.1 2013/05/01 19:58:26 imil Exp $

if_tun.h can be found in net/tun

--- openbsd-compat/port-tun.c.orig	2010-08-10 02:47:42.000000000 +0000
+++ openbsd-compat/port-tun.c
@@ -110,6 +110,10 @@ sys_tun_open(int tun, int mode)
 #include <sys/socket.h>
 #include <net/if.h>
 
+#ifdef HAVE_NET_TUN_IF_TUN_H
+#include <net/tun/if_tun.h>
+#endif
+
 #ifdef HAVE_NET_IF_TUN_H
 #include <net/if_tun.h>
 #endif
