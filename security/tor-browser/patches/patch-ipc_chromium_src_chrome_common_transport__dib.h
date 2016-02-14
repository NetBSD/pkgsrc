$NetBSD: patch-ipc_chromium_src_chrome_common_transport__dib.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- ipc/chromium/src/chrome/common/transport_dib.h.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/chromium/src/chrome/common/transport_dib.h
@@ -70,7 +70,7 @@ class TransportDIB {
   typedef base::SharedMemoryHandle Handle;
   // On Mac, the inode number of the backing file is used as an id.
   typedef base::SharedMemoryId Id;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   typedef int Handle;  // These two ints are SysV IPC shared memory keys
   typedef int Id;
 #endif
