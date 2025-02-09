$NetBSD: patch-src_alire_alire-directories.adb,v 1.1 2025/02/09 13:34:24 wiz Exp $

Add NetBSD support

--- src/alire/alire-directories.adb.orig	2024-03-21 00:22:58.000000000 +0200
+++ src/alire/alire-directories.adb	2024-04-09 17:50:42.084239096 +0300
@@ -146,7 +146,7 @@
       Keep_Links : constant String
         := (case Platforms.Current.Operating_System is
                when Linux           => "-d",
-               when FreeBSD | MacOS => "-R",
+               when FreeBSD | MacOS | NetBSD => "-R",
                when others          =>
                   raise Program_Error with "Unsupported operation");
    begin
