$NetBSD: patch-os__dep.c,v 1.1 2018/12/20 23:55:25 wiz Exp $

Fix NetBSD PaX case.
https://github.com/ivmai/bdwgc/commit/f70a2fe9058f655bb75759f7b9ec534fa27ca949

--- os_dep.c.orig	2018-09-05 07:37:07.000000000 +0000
+++ os_dep.c
@@ -2632,8 +2632,10 @@ GC_INNER void GC_remap(ptr_t start, size
 #   else
       /* It was already remapped with PROT_NONE. */
       {
-#       ifdef NACL
+#       if defined(NACL) || defined(NETBSD)
           /* NaCl does not expose mprotect, but mmap should work fine.  */
+          /* In case of NetBSD, mprotect fails (unlike mmap) even       */
+          /* without PROT_EXEC if PaX MPROTECT feature is enabled.      */
           void *result = mmap(start_addr, len, (PROT_READ | PROT_WRITE)
                                     | (GC_pages_executable ? PROT_EXEC : 0),
                                    MAP_PRIVATE | MAP_FIXED | OPT_MAP_ANON,
