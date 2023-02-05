$NetBSD: patch-widget_gtk_WaylandDMABufSurface.cpp,v 1.1 2023/02/05 08:32:24 he Exp $

--- widget/gtk/WaylandDMABufSurface.cpp.orig	2020-08-28 21:34:04.000000000 +0000
+++ widget/gtk/WaylandDMABufSurface.cpp
@@ -18,7 +18,9 @@
 #include <sys/time.h>
 #include <dlfcn.h>
 #include <sys/mman.h>
+#if !defined(__NetBSD__)
 #include <sys/eventfd.h>
+#endif
 #include <poll.h>
 
 #include "mozilla/widget/gbm.h"
@@ -91,6 +93,7 @@ void WaylandDMABufSurface::GlobalRefAdd(
 }
 
 void WaylandDMABufSurface::GlobalRefCountCreate() {
+#if !defined(__NetBSD__)
   MOZ_ASSERT(!mGlobalRefCountFd);
   mGlobalRefCountFd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK | EFD_SEMAPHORE);
   if (mGlobalRefCountFd < 0) {
@@ -98,6 +101,7 @@ void WaylandDMABufSurface::GlobalRefCoun
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void WaylandDMABufSurface::GlobalRefCountImport(int aFd) {
