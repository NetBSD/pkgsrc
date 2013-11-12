$NetBSD: patch-mozilla_ipc_chromium_src_chrome_common_transport__dib.h,v 1.4 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/src/chrome/common/transport_dib.h.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/chrome/common/transport_dib.h
@@ -70,7 +70,7 @@ class TransportDIB {
   typedef base::SharedMemoryHandle Handle;
   // On Mac, the inode number of the backing file is used as an id.
   typedef base::SharedMemoryId Id;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   typedef int Handle;  // These two ints are SysV IPC shared memory keys
   typedef int Id;
 #endif
