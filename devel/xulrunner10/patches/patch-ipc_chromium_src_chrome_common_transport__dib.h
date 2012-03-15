$NetBSD: patch-ipc_chromium_src_chrome_common_transport__dib.h,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- ipc/chromium/src/chrome/common/transport_dib.h.orig	2012-03-09 22:20:17.000000000 +0000
+++ ipc/chromium/src/chrome/common/transport_dib.h
@@ -7,7 +7,7 @@
 
 #include "base/basictypes.h"
 
-#if defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
 #include "base/shared_memory.h"
 #endif
 
@@ -66,7 +66,7 @@ class TransportDIB {
     uint32 sequence_num;
   };
   typedef HandleAndSequenceNum Id;
-#elif defined(OS_MACOSX)
+#elif defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   typedef base::SharedMemoryHandle Handle;
   // On Mac, the inode number of the backing file is used as an id.
   typedef base::SharedMemoryId Id;
@@ -108,7 +108,7 @@ class TransportDIB {
 
  private:
   TransportDIB();
-#if defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   explicit TransportDIB(base::SharedMemoryHandle dib);
   base::SharedMemory shared_memory_;
   uint32 sequence_num_;
