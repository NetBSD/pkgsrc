$NetBSD: patch-libgcc_unwind-dw2-fde-dip.c,v 1.1 2012/06/23 22:13:02 marino Exp $

Add dl_iterate_phdr error handling support for all BSDs.  The NetBSD and
OpenBSD code will not run until dl_iterate_phdr detection in the configure
script is uncommented.

--- libgcc/unwind-dw2-fde-dip.c.orig	2011-11-02 15:26:35.000000000 +0000
+++ libgcc/unwind-dw2-fde-dip.c
@@ -54,11 +54,19 @@
 #endif
 
 #if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
-    && defined(__FreeBSD__) && __FreeBSD__ >= 7
+    && defined(TARGET_DL_ITERATE_PHDR) \
+    && (defined(__FreeBSD__) || defined(__DragonFly__))
 # define ElfW __ElfN
 # define USE_PT_GNU_EH_FRAME
 #endif
 
+#if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
+    && defined(TARGET_DL_ITERATE_PHDR) \
+    && (defined(__OpenBSD__) || defined(__NetBSD__))
+# define ElfW(n) Elf_##n
+# define USE_PT_GNU_EH_FRAME
+#endif
+
 #if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
     && defined(TARGET_DL_ITERATE_PHDR) \
     && defined(__sun__) && defined(__svr4__)
