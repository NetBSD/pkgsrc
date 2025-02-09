$NetBSD: patch-src_alire_alire-platforms.ads,v 1.2 2025/02/09 13:34:24 wiz Exp $

Add NetBSD support

--- src/alire/alire-platforms.ads.orig	2024-03-21 00:22:58.000000000 +0200
+++ src/alire/alire-platforms.ads	2024-04-09 16:21:29.009936835 +0300
@@ -24,6 +24,7 @@
                               Linux,
                               MacOS,
                               Windows,
+                              NetBSD,
                               OS_Unknown);
    subtype Known_Operating_Systems is
      Operating_Systems range
