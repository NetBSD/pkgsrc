$NetBSD: patch-src_alire_alire-platforms.ads,v 1.3 2025/04/27 10:43:42 dkazankov Exp $

Add NetBSD support

--- src/alire/alire-platforms.ads.orig	2025-03-04 10:02:00.000000000 +0000
+++ src/alire/alire-platforms.ads
@@ -22,6 +22,7 @@
 
    type Operating_Systems is (FreeBSD,
                               OpenBSD,
+                              NetBSD,
                               Linux,
                               MacOS,
                               Windows,
