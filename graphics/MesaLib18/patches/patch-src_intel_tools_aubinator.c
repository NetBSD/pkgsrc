$NetBSD: patch-src_intel_tools_aubinator.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Use the more portable shm_open as an alternative to memfd_create

--- src/intel/tools/aubinator.c.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/intel/tools/aubinator.c
@@ -46,16 +46,6 @@
 #include "common/gen_gem.h"
 #include "intel_aub.h"
 
-#ifndef HAVE_MEMFD_CREATE
-#include <sys/syscall.h>
-
-static inline int
-memfd_create(const char *name, unsigned int flags)
-{
-   return syscall(SYS_memfd_create, name, flags);
-}
-#endif
-
 /* Below is the only command missing from intel_aub.h in libdrm
  * So, reuse intel_aub.h from libdrm and #define the
  * AUB_MI_BATCH_BUFFER_END as below
@@ -907,7 +897,12 @@ int main(int argc, char *argv[])
    if (isatty(1) && pager)
       setup_pager();
 
+
+#ifdef HAVE_MEMFD_CREATE
    mem_fd = memfd_create("phys memory", 0);
+#else
+   mem_fd = shm_open("phys memory", O_RDWR | O_CREAT | O_EXCL, S_IRWXU);
+#endif
 
    list_inithead(&maps);
 
