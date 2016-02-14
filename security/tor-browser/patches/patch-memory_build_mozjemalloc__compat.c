$NetBSD: patch-memory_build_mozjemalloc__compat.c,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- memory/build/mozjemalloc_compat.c.orig	2015-03-27 02:20:26.000000000 +0000
+++ memory/build/mozjemalloc_compat.c
@@ -131,6 +131,48 @@ compute_bin_unused(unsigned int narenas)
     return bin_unused;
 }
 
+static size_t
+compute_bin_unused(unsigned int narenas)
+{
+    size_t bin_unused = 0;
+
+    uint32_t nregs; // number of regions per run in the j-th bin
+    size_t reg_size; // size of regions served by the j-th bin
+    size_t curruns; // number of runs belonging to a bin
+    size_t curregs; // number of allocated regions in a bin
+
+    unsigned int nbins; // number of bins per arena
+    unsigned int i, j;
+
+    // curruns and curregs are not defined for uninitialized arenas,
+    // so we skip them when computing bin_unused. However, initialized
+    // arenas are not guaranteed to be sequential, so we must test each
+    // one when iterating below.
+    bool initialized[100]; // should be narenas, but MSVC doesn't have VLAs
+    size_t isz = sizeof(initialized) / sizeof(initialized[0]);
+
+    je_(mallctl)("arenas.initialized", initialized, &isz, NULL, 0);
+    CTL_GET("arenas.nbins", nbins);
+
+    for (j = 0; j < nbins; j++) {
+        CTL_I_GET("arenas.bin.0.nregs", nregs, j);
+        CTL_I_GET("arenas.bin.0.size", reg_size, j);
+
+        for (i = 0; i < narenas; i++) {
+            if (!initialized[i]) {
+                continue;
+            }
+
+            CTL_IJ_GET("stats.arenas.0.bins.0.curruns", curruns, i, j);
+            CTL_IJ_GET("stats.arenas.0.bins.0.curregs", curregs, i, j);
+
+            bin_unused += (nregs * curruns - curregs) * reg_size;
+        }
+    }
+
+    return bin_unused;
+}
+
 MOZ_JEMALLOC_API void
 jemalloc_stats_impl(jemalloc_stats_t *stats)
 {
