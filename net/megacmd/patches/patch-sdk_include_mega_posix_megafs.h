$NetBSD: patch-sdk_include_mega_posix_megafs.h,v 1.2 2025/02/15 07:40:13 wiz Exp $

* Use FSACCESS_CLASS of linux on BSDs

--- sdk/include/mega/posix/megafs.h.orig	2025-02-13 10:44:28.677854322 +0100
+++ sdk/include/mega/posix/megafs.h
@@ -192,7 +192,8 @@ private:
 
 };
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 
 #define FSACCESS_CLASS LinuxFileSystemAccess
 
