$NetBSD: patch-widget_gtk_DMABufSurface.cpp,v 1.2 2023/08/25 10:15:01 pho Exp $

No eventfd on NetBSD 9 and older, fix build

--- widget/gtk/DMABufSurface.cpp.orig	2023-08-14 18:20:04.000000000 +0000
+++ widget/gtk/DMABufSurface.cpp
@@ -18,7 +18,9 @@
 #include <sys/time.h>
 #include <dlfcn.h>
 #include <sys/mman.h>
+#ifndef __NetBSD__
 #include <sys/eventfd.h>
+#endif
 #include <poll.h>
 #include <sys/ioctl.h>
 
@@ -147,6 +149,9 @@ void DMABufSurface::GlobalRefAdd() {
 }
 
 void DMABufSurface::GlobalRefCountCreate() {
+#ifdef __NetBSD__
+  mGlobalRefCountFd = 0;
+#else
   LOGDMABUFREF(("DMABufSurface::GlobalRefCountCreate UID %d", mUID));
   MOZ_DIAGNOSTIC_ASSERT(!mGlobalRefCountFd);
   // Create global ref count initialized to 0,
@@ -159,6 +164,7 @@ void DMABufSurface::GlobalRefCountCreate
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void DMABufSurface::GlobalRefCountImport(int aFd) {
