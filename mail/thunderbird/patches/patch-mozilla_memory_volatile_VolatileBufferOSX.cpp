$NetBSD: patch-mozilla_memory_volatile_VolatileBufferOSX.cpp,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/memory/volatile/VolatileBufferOSX.cpp.orig	2015-06-08 17:49:26.000000000 +0000
+++ mozilla/memory/volatile/VolatileBufferOSX.cpp
@@ -47,7 +47,14 @@ VolatileBuffer::Init(size_t aSize, size_
   }
 
 heap_alloc:
+#if defined(HAVE_POSIX_MEMALIGN)
   (void)moz_posix_memalign(&mBuf, aAlignment, aSize);
+#else
+  MOZ_RELEASE_ASSERT(
+      !(aAlignment > (size_t)getpagesize()),
+      "Cannot fallback to valloc(3): alignment is larger than the page size");
+  mBuf = valloc(aSize);
+#endif
   mHeap = true;
   return !!mBuf;
 }
