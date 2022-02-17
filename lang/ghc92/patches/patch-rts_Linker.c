$NetBSD: patch-rts_Linker.c,v 1.2 2022/02/17 11:59:24 pho Exp $

NetBSD-specific way of switching pages from rw- to r-x. Should not be
upstreamed until we figure out why the hunk #0 is necessary.

Even when the RTS linker is not used, libraries/ghci/GHCi/InfoTable.hsc
(fillExecBuffer) calls rts/ExecPage.c (allocateExecPage) to store some
executable code, which in turn calls mmapForLinker() and fails.

Minimal test case:
https://gist.github.com/depressed-pho/a629247b48b3e6178e35a14c62e9d44f

tech-kern thread:
https://mail-index.netbsd.org/tech-kern/2022/02/17/msg027969.html

This was previously not an issue, until
https://gitlab.haskell.org/ghc/ghc/-/issues/20051 happened and lead to
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/6155

--- rts/Linker.c.orig	2021-10-28 20:41:34.000000000 +0000
+++ rts/Linker.c
@@ -1115,9 +1115,17 @@ mmapForLinker (size_t bytes, uint32_t pr
 mmap_again:
 #endif
 
+#if defined(DYNAMIC) && defined(netbsd_HOST_OS)
+   /* Dynamic RTS only uses this function for allocating some anonymous pages
+    * for code generated on-the-fly, which doesn't need to be in a certain
+    * range. On NetBSD, when ASLR is enabled, specifying an address hint
+    * sometimes fail with ENOMEM even when MAP_FIXED is not used.
+    */
+#else
    if (mmap_32bit_base != 0) {
        map_addr = mmap_32bit_base;
    }
+#endif
 
    IF_DEBUG(linker,
             debugBelch("mmapForLinker: \tprotection %#0x\n", prot));
@@ -1218,7 +1226,20 @@ mmap_again:
 void *
 mmapAnonForLinker (size_t bytes)
 {
-  return mmapForLinker (bytes, PROT_READ|PROT_WRITE, MAP_ANONYMOUS, -1, 0);
+    int prot;
+
+#if defined(netbsd_HOST_OS)
+    /* PROT_MPROTECT(PROT_EXEC) means that the pages are going to be marked as
+     * executable in the future. On NetBSD requesting additional permissions with
+     * mprotect(2) only succeeds when permissions were initially requested in this
+     * manner.
+     */
+    prot = PROT_READ|PROT_WRITE|PROT_MPROTECT(PROT_EXEC);
+#else
+    prot = PROT_READ|PROT_WRITE;
+#endif
+
+    return mmapForLinker (bytes, prot, MAP_ANONYMOUS, -1, 0);
 }
 
 void munmapForLinker (void *addr, size_t bytes, const char *caller)
