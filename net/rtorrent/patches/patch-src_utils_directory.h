$NetBSD: patch-src_utils_directory.h,v 1.1 2018/06/24 16:59:52 adam Exp $

Fix build under Solaris and DragonFly.

--- src/utils/directory.h.orig	2012-03-29 14:06:11.000000000 +0100
+++ src/utils/directory.h	2012-05-14 23:40:30.000000000 +0100
@@ -50,7 +50,7 @@
   // The name and types should match POSIX.
   uint32_t            d_fileno;
   uint32_t            d_reclen; //Not used. Messes with Solaris.
-  uint8_t             d_type;
+  uint32_t             d_type;
 
   std::string         d_name;
 };
