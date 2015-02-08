$NetBSD: patch-jdk_src_solaris_bin_ergo.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

No _SC_PHYS_PAGES on NetBSD < 6.
we could use the hw.physmem64 sysctl instead of returning 0,
although I don't think this code is actually used.

--- jdk/src/solaris/bin/ergo.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/bin/ergo.c
@@ -100,7 +100,11 @@ ServerClassMachineImpl(void) {
 /* Compute physical memory by asking the OS */
 uint64_t
 physical_memory(void) {
+#ifdef _SC_PHYS_PAGES
   const uint64_t pages     = (uint64_t) sysconf(_SC_PHYS_PAGES);
+#else
+  const uint64_t pages     = 0;
+#endif
   const uint64_t page_size = (uint64_t) sysconf(_SC_PAGESIZE);
   const uint64_t result    = pages * page_size;
 # define UINT64_FORMAT "%" PRIu64
