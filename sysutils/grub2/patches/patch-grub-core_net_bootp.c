$NetBSD: patch-grub-core_net_bootp.c,v 1.1 2016/05/03 14:53:14 nonaka Exp $

--- grub-core/net/bootp.c.orig  2012-06-22 05:15:48.000000000 +0900
+++ grub-core/net/bootp.c       2016-04-27 22:57:02.990825737 +0900
@@ -52,9 +52,9 @@ set_env_limn_ro (const char *intername,
 }

 static void
-parse_dhcp_vendor (const char *name, void *vend, int limit, int *mask)
+parse_dhcp_vendor (const char *name, const void *vend, int limit, int *mask)
 {
-  grub_uint8_t *ptr, *ptr0;
+  const grub_uint8_t *ptr, *ptr0;

   ptr = ptr0 = vend;

