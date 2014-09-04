$NetBSD: patch-libgcc_unwind-dw2-fde-dip.c,v 1.1 2014/09/04 18:43:11 jperkin Exp $

Add dl_iterate_phdr error handling support for all BSDs.  The NetBSD and
OpenBSD code will not run until dl_iterate_phdr detection in the configure
script is uncommented.

--- libgcc/unwind-dw2-fde-dip.c.orig	2014-01-02 22:25:22.000000000 +0000
+++ libgcc/unwind-dw2-fde-dip.c
@@ -58,13 +58,15 @@
 #endif
 
 #if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
-    && defined(__FreeBSD__) && __FreeBSD__ >= 7
+    && defined(TARGET_DL_ITERATE_PHDR) \
+    && (defined(__FreeBSD__) || defined(__DragonFly__))
 # define ElfW __ElfN
 # define USE_PT_GNU_EH_FRAME
 #endif
 
 #if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
-    && defined(__OpenBSD__)
+    && defined(TARGET_DL_ITERATE_PHDR) \
+    && (defined(__OpenBSD__) || defined(__NetBSD__))
 # define ElfW(type) Elf_##type
 # define USE_PT_GNU_EH_FRAME
 #endif
