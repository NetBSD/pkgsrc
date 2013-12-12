$NetBSD: patch-rts_Linker.c,v 1.1 2013/12/12 12:47:17 obache Exp $

Support 64-bit x86 SunOS.

--- rts/Linker.c.orig	2013-04-18 21:22:46.000000000 +0000
+++ rts/Linker.c
@@ -75,7 +75,8 @@
     (   defined(linux_HOST_OS)     || defined(freebsd_HOST_OS) || \
         defined(dragonfly_HOST_OS) || defined(netbsd_HOST_OS ) || \
         defined(openbsd_HOST_OS  ) || defined(darwin_HOST_OS ) || \
-        defined(kfreebsdgnu_HOST_OS) || defined(gnu_HOST_OS)))
+        defined(kfreebsdgnu_HOST_OS) || defined(gnu_HOST_OS) || \
+        defined(solari2_HOST_OS)))
 /* Don't use mmap on powerpc_HOST_ARCH as mmap doesn't support
  * reallocating but we need to allocate jump islands just after each
  * object images. Otherwise relative branches to jump islands can fail
@@ -4014,6 +4015,9 @@ ocResolve_PEi386 ( ObjectCode* oc )
 #  define ELF_TARGET_386    /* Used inside <elf.h> */
 #elif defined(x86_64_HOST_ARCH)
 #  define ELF_TARGET_X64_64
+#  if defined(solaris2_HOST_OS)
+#    define ELF_TARGET_AMD64
+#  endif
 #  define ELF_64BIT
 #endif
 
