$NetBSD: patch-bridges_source_cpp_uno_shared_vtablefactory.cxx,v 1.2 2025/04/16 14:55:39 manu Exp $

posix_fallocate() may be available but unimplemented for a 
given filesystem. Detect that situation once and use ftruncate()
instead.

Here LibreOffice need to mmap() a memory block RWX. At least on NetBSD,
PAX mprofect will prevent this. LibreOffice has an alternative
implementation that double mmap() a mkstemp() file, one time RW and
the second tume RX. Make sure the mmap() RWX is only tried once.

A stripped down version was committed upstream, it will make this
patch obsolete starting with LibreOffice 25.8.0
https://git.libreoffice.org/core/+/9fb26786b75e30df593378954044af4e4753a192%5E%2
1/

--- ./bridges/source/cpp_uno/shared/vtablefactory.cxx.orig
+++ ./bridges/source/cpp_uno/shared/vtablefactory.cxx
@@ -245,17 +245,26 @@
 
 #ifdef USE_DOUBLE_MMAP
 bool VtableFactory::createBlock(Block &block, sal_Int32 slotCount) const
 {
+#if defined(HAVE_POSIX_FALLOCATE)
+    static int use_fallocate = 1;
+#else
+    static int use_fallocate = 0;
+#endif
+    static int use_double_mmap = 0;
     std::size_t size = getBlockSize(slotCount);
     std::size_t pagesize = sysconf(_SC_PAGESIZE);
     block.size = (size + (pagesize - 1)) & ~(pagesize - 1);
     block.fd = -1;
 
-    // Try non-doublemmaped allocation first:
-    block.start = block.exec = rtl_arena_alloc(m_arena, &block.size);
-    if (block.start != nullptr) {
-        return true;
+    // try non-doublemmaped allocation first
+    if (!use_double_mmap) {
+        block.start = block.exec = rtl_arena_alloc(m_arena, &block.size);
+        if (block.start != nullptr) {
+            return true;
+        }
+        use_double_mmap = 1;
     }
 
     osl::Security aSecurity;
     OUString strDirectory;
@@ -280,20 +289,30 @@
             break;
         }
         unlink(tmpfname.get());
         tmpfname.reset();
+
+        int err;
 #if defined(HAVE_POSIX_FALLOCATE)
-        int err = posix_fallocate(block.fd, 0, block.size);
-#else
-        int err = ftruncate(block.fd, block.size);
+retry:
+        if (use_fallocate) {
+            err = posix_fallocate(block.fd, 0, block.size);
+            if (err == EOPNOTSUPP) {
+                use_fallocate = 0;
+                goto retry;
+            }
+        }
+        else
 #endif
-        if (err != 0)
         {
-#if defined(HAVE_POSIX_FALLOCATE)
-            SAL_WARN("bridges", "posix_fallocate failed with code " << err);
-#else
-            SAL_WARN("bridges", "truncation of executable memory area failed with code " << err);
-#endif
+            err = ftruncate(block.fd, block.size);
+        }
+
+        if (err != 0) {
+            if (use_fallocate)
+                SAL_WARN("bridges", "posix_fallocate failed with code " << err);
+            else
+                SAL_WARN("bridges", "truncation of executable memory area failed with code " << err);
             close(block.fd);
             block.fd = -1;
             break;
         }
