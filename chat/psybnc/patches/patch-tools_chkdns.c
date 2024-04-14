$NetBSD: patch-tools_chkdns.c,v 1.1 2024/04/14 08:23:22 wiz Exp $

Fix libcares detection (not found because of deprecated symbol).

--- tools/chkdns.c.orig	2024-04-14 08:20:59.195730495 +0000
+++ tools/chkdns.c
@@ -30,6 +30,6 @@
 int main(int argc, char **argv)
 {
     ares_channel resolver;
-    ares_init(&resolver);
+    ares_init_options(&resolver, NULL, 0);
     return 0;
 }
