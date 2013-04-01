$NetBSD: patch-libgcc_unwind-dw2-fde-dip.c,v 1.1 2013/04/01 21:06:17 wiz Exp $

--- libgcc/unwind-dw2-fde-dip.c.orig	2013-02-04 19:06:20.000000000 +0000
+++ libgcc/unwind-dw2-fde-dip.c
@@ -58,13 +58,14 @@
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
+    && (defined(__OpenBSD__) || defined(__NetBSD__))
 # define ElfW(type) Elf_##type
 # define USE_PT_GNU_EH_FRAME
 #endif
