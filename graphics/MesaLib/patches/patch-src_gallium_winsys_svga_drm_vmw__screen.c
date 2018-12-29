$NetBSD: patch-src_gallium_winsys_svga_drm_vmw__screen.c,v 1.2 2018/12/29 13:38:53 triaxx Exp $

* Solaris needs sys/mkdev.h for major(2).
* Linux needs sys/sysmacros.h for major(2).

--- src/gallium/winsys/svga/drm/vmw_screen.c.orig	2016-01-22 15:44:31.000000000 +0000
+++ src/gallium/winsys/svga/drm/vmw_screen.c
@@ -32,6 +32,11 @@
 #include "pipe/p_compiler.h"
 #include "util/u_hash_table.h"
 #include <sys/types.h>
+#ifdef __sun
+#include <sys/mkdev.h> /* for major(2) */
+#elif defined(__linux__)
+#include <sys/sysmacros.h>
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 
