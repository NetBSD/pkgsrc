$NetBSD: patch-src_utils_directory.h,v 1.2 2024/10/04 09:02:01 adam Exp $

Fix build under Solaris and DragonFly.

--- src/utils/directory.h.orig	2024-09-07 06:29:21.000000000 +0000
+++ src/utils/directory.h
@@ -50,7 +50,7 @@ struct directory_entry {
   // The name and types should match POSIX.
   uint32_t            s_fileno;
   uint32_t            s_reclen; //Not used. Messes with Solaris.
-  uint8_t             s_type;
+  uint32_t            s_type;
 
   std::string         s_name;
 };
