$NetBSD: patch-src_elf.h,v 1.1 2026/11/25 10:04:05 pho Exp $

See patches/src_patchelf.cc

--- src/elf.h.orig	2026-11-25 08:28:15.064858073 +0000
+++ src/elf.h
@@ -453,8 +453,11 @@ typedef struct
 #define SHT_CHECKSUM	  0x6ffffff8	/* Checksum for DSO content.  */
 #define SHT_LOSUNW	  0x6ffffffa	/* Sun-specific low bound.  */
 #define SHT_SUNW_move	  0x6ffffffa
-#define SHT_SUNW_COMDAT   0x6ffffffb
+#define SHT_SUNW_COMDAT	  0x6ffffffb
 #define SHT_SUNW_syminfo  0x6ffffffc
+#define SHT_SUNW_verdef	  0x6ffffffd	/* Sun-specific version definition. */
+#define SHT_SUNW_verneed  0x6ffffffe	/* Sun-specific version needs. */
+#define SHT_SUNW_versym	  0x6fffffff	/* Sun-specific version symbols. */
 #define SHT_GNU_verdef	  0x6ffffffd	/* Version definition section.  */
 #define SHT_GNU_verneed	  0x6ffffffe	/* Version needs section.  */
 #define SHT_GNU_versym	  0x6fffffff	/* Version symbol table.  */
