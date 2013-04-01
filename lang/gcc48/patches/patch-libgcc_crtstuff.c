$NetBSD: patch-libgcc_crtstuff.c,v 1.1 2013/04/01 21:06:17 wiz Exp $

Currently dl_iterate_phdr error handling is hardcoded for FreeBSD 7+
Expand code to handle all BSDs even though detection is only active for
FreeBSD and DragonFly currently.

--- libgcc/crtstuff.c.orig	2011-12-06 21:35:41.000000000 +0000
+++ libgcc/crtstuff.c
@@ -81,11 +81,19 @@ call_ ## FUNC (void)					\
 }
 #endif
 
+#if defined(TARGET_DL_ITERATE_PHDR) && \
+   ( defined(__FreeBSD__)              \
+  || defined(__OpenBSD__)              \
+  || defined(__NetBSD__)               \
+  || defined(__DragonFly__))
+#define BSD_DL_ITERATE_PHDR_AVAILABLE
+#endif
+
 #if defined(OBJECT_FORMAT_ELF) \
     && !defined(OBJECT_FORMAT_FLAT) \
     && defined(HAVE_LD_EH_FRAME_HDR) \
     && !defined(inhibit_libc) && !defined(CRTSTUFFT_O) \
-    && defined(__FreeBSD__) && __FreeBSD__ >= 7
+    && defined(BSD_DL_ITERATE_PHDR_AVAILABLE)
 #include <link.h>
 # define USE_PT_GNU_EH_FRAME
 #endif
