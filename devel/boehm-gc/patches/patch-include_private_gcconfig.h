$NetBSD: patch-include_private_gcconfig.h,v 1.8 2025/12/08 02:09:56 mrg Exp $

Recognize riscv on netbsd. https://github.com/ivmai/bdwgc/issues/556
Add support for 64-bit NetBSD/mips.

--- include/private/gcconfig.h.orig	2023-05-26 11:56:18.000000000 -0700
+++ include/private/gcconfig.h	2025-12-07 17:58:41.769883216 -0800
@@ -682,7 +682,7 @@ EXTERN_C_BEGIN
 #   define mach_type_known
 # endif
 # if defined(__riscv) && (defined(FREEBSD) || defined(LINUX) \
-                          || defined(OPENBSD))
+                          || defined(NETBSD) || defined(OPENBSD))
 #   define RISCV
 #   define mach_type_known
 # endif
@@ -1804,12 +1804,17 @@ EXTERN_C_BEGIN
 #       define ALIGNMENT 4
 #   endif
 #   ifdef NETBSD
-#     define ALIGNMENT 4
+#     ifdef _MIPS_SZPTR
+#       define CPP_WORDSZ _MIPS_SZPTR
+#       define ALIGNMENT (_MIPS_SZPTR/8)
+#     else
+#       define ALIGNMENT 4
+#     endif
 #     ifndef __ELF__
 #       define DATASTART ((ptr_t)0x10000000)
 #       define STACKBOTTOM ((ptr_t)0x7ffff000)
 #     endif
-#  endif
+#   endif
 #  ifdef OPENBSD
 #     define CPP_WORDSZ 64 /* all OpenBSD/mips platforms are 64-bit */
 #     define ALIGNMENT 8
