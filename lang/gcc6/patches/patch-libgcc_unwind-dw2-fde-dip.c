$NetBSD: patch-libgcc_unwind-dw2-fde-dip.c,v 1.1 2016/09/12 22:13:54 maya Exp $

--- libgcc/unwind-dw2-fde-dip.c.orig	2014-05-21 11:08:58.000000000 +0000
+++ libgcc/unwind-dw2-fde-dip.c
@@ -65,7 +65,7 @@
 #endif
 
 #if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
-    && defined(__OpenBSD__)
+    && defined(__OpenBSD__) || defined(__NetBSD__)
 # define ElfW(type) Elf_##type
 # define USE_PT_GNU_EH_FRAME
 #endif
