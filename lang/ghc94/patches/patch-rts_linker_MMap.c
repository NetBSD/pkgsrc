$NetBSD: patch-rts_linker_MMap.c,v 1.3 2023/01/21 18:31:22 pho Exp $

Hunk #0-2, #6:
    NetBSD-specific way of switching pages from rw- to r-x. Even when the
    RTS linker is not used, libraries/ghci/GHCi/InfoTable.hsc
    (fillExecBuffer) calls rts/ExecPage.c (allocateExecPage) to store some
    executable code, then calls freezeExecPage() and fails. If we were to
    disable PaX MPROTECT entirely then we could omit this change, but of
    course that's not the right thing to do.

    Merge request:
    https://gitlab.haskell.org/ghc/ghc/-/merge_requests/9769

Hunk #3-5:
    NetBSD mmap(2) doesn't work the same way as that of Linux. We
    essentially can't use the hint address to map a new page based on the
    address of the previously mapped one.

    Merge request:
    https://gitlab.haskell.org/ghc/ghc/-/merge_requests/9769

    Minimal test case:
    https://gist.github.com/depressed-pho/a629247b48b3e6178e35a14c62e9d44f

    tech-kern thread:
    https://mail-index.netbsd.org/tech-kern/2022/02/17/msg027969.html

--- rts/linker/MMap.c.orig	2022-12-23 16:19:02.000000000 +0000
+++ rts/linker/MMap.c
@@ -46,6 +46,8 @@ static const char *memoryAccessDescripti
   case MEM_NO_ACCESS:    return "no-access";
   case MEM_READ_ONLY:    return "read-only";
   case MEM_READ_WRITE:   return "read-write";
+  case MEM_READ_WRITE_THEN_READ_EXECUTE:
+                         return "read-write-then-read-execute";
   case MEM_READ_EXECUTE: return "read-execute";
   case MEM_READ_WRITE_EXECUTE:
                          return "read-write-execute";
@@ -196,6 +198,8 @@ memoryAccessToProt(MemoryAccess access)
   case MEM_NO_ACCESS:    return PAGE_NOACCESS;
   case MEM_READ_ONLY:    return PAGE_READONLY;
   case MEM_READ_WRITE:   return PAGE_READWRITE;
+  case MEM_READ_WRITE_THEN_READ_EXECUTE:
+                         return PAGE_READWRITE;
   case MEM_READ_EXECUTE: return PAGE_EXECUTE_READ;
   case MEM_READ_WRITE_EXECUTE:
                          return PAGE_EXECUTE_READWRITE;
@@ -258,6 +262,17 @@ memoryAccessToProt(MemoryAccess access)
     case MEM_NO_ACCESS:    return 0;
     case MEM_READ_ONLY:    return PROT_READ;
     case MEM_READ_WRITE:   return PROT_READ | PROT_WRITE;
+    case MEM_READ_WRITE_THEN_READ_EXECUTE:
+#  if defined(netbsd_HOST_OS)
+        /* PROT_MPROTECT(PROT_EXEC) means that the pages are going to be
+         * marked as executable in the future. On NetBSD requesting
+         * additional permissions with mprotect(2) only succeeds when
+         * permissions were initially requested in this manner.
+         */
+                           return PROT_READ | PROT_WRITE | PROT_MPROTECT(PROT_EXEC);
+#  else
+                           return PROT_READ | PROT_WRITE;
+#  endif
     case MEM_READ_EXECUTE: return PROT_READ | PROT_EXEC;
     case MEM_READ_WRITE_EXECUTE:
                            return PROT_READ | PROT_WRITE | PROT_EXEC;
@@ -301,6 +316,23 @@ nearImage(void) {
     return &region;
 }
 
+/* mmap(2) works differently on NetBSD. When a hint address is provided, it
+ * searches for a free region at or below the hint, and *never* above
+ * it. This means we really can't search for free regions incrementally on
+ * the user side. Let the kernel do it for us.
+ */
+static void *
+mmapAnywhere (
+        size_t bytes,
+        MemoryAccess access,
+        uint32_t flags,
+        int fd,
+        int offset)
+{
+    int prot = memoryAccessToProt(access);
+    return doMmap(NULL, bytes, prot, flags, fd, offset);
+}
+
 static void *
 mmapInRegion (
         struct MemoryRegion *region,
@@ -358,17 +390,27 @@ mmapForLinker (size_t bytes, MemoryAcces
     IF_DEBUG(linker_verbose, debugBelch("mmapForLinker: start\n"));
     if (RtsFlags.MiscFlags.linkerAlwaysPic) {
         /* make no attempt at mapping low memory if we are assuming PIC */
+#if defined(netbsd_HOST_OS)
+        region = NULL;
+#else
         region = &allMemory;
+#endif
     } else {
         region = nearImage();
     }
 
     /* Use MAP_32BIT if appropriate */
-    if (region->end <= (void *) 0xffffffff) {
+    if (region && region->end <= (void *) 0xffffffff) {
         flags |= TRY_MAP_32BIT;
     }
 
-    void *result = mmapInRegion(region, bytes, access, flags, fd, offset);
+    void *result;
+    if (region) {
+        result = mmapInRegion(region, bytes, access, flags, fd, offset);
+    }
+    else {
+        result = mmapAnywhere(bytes, access, flags, fd, offset);
+    }
     IF_DEBUG(linker_verbose,
              debugBelch("mmapForLinker: mapped %zd bytes starting at %p\n",
                         bytes, result));
@@ -383,7 +425,7 @@ mmapForLinker (size_t bytes, MemoryAcces
 void *
 mmapAnonForLinker (size_t bytes)
 {
-    return mmapForLinker (bytes, MEM_READ_WRITE, MAP_ANONYMOUS, -1, 0);
+    return mmapForLinker (bytes, MEM_READ_WRITE_THEN_READ_EXECUTE, MAP_ANONYMOUS, -1, 0);
 }
 
 void munmapForLinker (void *addr, size_t bytes, const char *caller)
