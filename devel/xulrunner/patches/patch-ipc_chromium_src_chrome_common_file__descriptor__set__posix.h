$NetBSD: patch-ipc_chromium_src_chrome_common_file__descriptor__set__posix.h,v 1.1 2012/08/28 12:42:01 ryoon Exp $

--- ipc/chromium/src/chrome/common/file_descriptor_set_posix.h.orig	2012-08-08 20:20:07.000000000 +0000
+++ ipc/chromium/src/chrome/common/file_descriptor_set_posix.h
@@ -30,7 +30,7 @@ class FileDescriptorSet : public base::R
   // In debugging mode, it's a fatal error to try and add more than this number
   // of descriptors to a FileDescriptorSet.
   enum {
-    MAX_DESCRIPTORS_PER_MESSAGE = 4,
+    MAX_DESCRIPTORS_PER_MESSAGE = 4
   };
 
   // ---------------------------------------------------------------------------
