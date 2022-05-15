$NetBSD: patch-openbsd-compat_port-net.c,v 1.1 2022/05/15 19:21:56 wiz Exp $

if_tun.h can be found in net/tun

--- openbsd-compat/port-net.c.orig	2020-09-27 07:25:01.000000000 +0000
+++ openbsd-compat/port-net.c
@@ -135,6 +135,10 @@ sys_set_process_rdomain(const char *name
  * System-specific tunnel open function
  */
 
+#ifdef HAVE_NET_TUN_IF_TUN_H
+#include <net/tun/if_tun.h>
+#endif
+
 #if defined(SSH_TUN_LINUX)
 #include <linux/if_tun.h>
 #define TUN_CTRL_DEV "/dev/net/tun"
