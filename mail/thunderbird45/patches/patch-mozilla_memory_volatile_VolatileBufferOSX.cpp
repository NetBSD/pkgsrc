$NetBSD: patch-mozilla_memory_volatile_VolatileBufferOSX.cpp,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/memory/volatile/VolatileBufferOSX.cpp.orig	2016-04-07 21:33:25.000000000 +0000
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
