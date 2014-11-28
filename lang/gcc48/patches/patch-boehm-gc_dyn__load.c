$NetBSD: patch-boehm-gc_dyn__load.c,v 1.2 2014/11/28 09:57:32 obache Exp $

--- boehm-gc/dyn_load.c.orig	2012-11-04 22:56:02.000000000 +0000
+++ boehm-gc/dyn_load.c
@@ -61,6 +61,7 @@
     !defined(HPUX) && !(defined(LINUX) && defined(__ELF__)) && \
     !defined(RS6000) && !defined(SCO_ELF) && !defined(DGUX) && \
     !(defined(FREEBSD) && defined(__ELF__)) && \
+    !(defined(OPENBSD) && defined(__ELF__)) && \
     !(defined(NETBSD) && defined(__ELF__)) && !defined(HURD) && \
     !defined(DARWIN)
  --> We only know how to find data segments of dynamic libraries for the
@@ -100,9 +101,12 @@
 
 #if defined(LINUX) && defined(__ELF__) || defined(SCO_ELF) || \
     (defined(FREEBSD) && defined(__ELF__)) || defined(DGUX) || \
+    (defined(OPENBSD) && defined(__ELF__)) || \
     (defined(NETBSD) && defined(__ELF__)) || defined(HURD)
 #   include <stddef.h>
+#ifndef OPENBSD
 #   include <elf.h>
+#endif
 #   include <link.h>
 #endif
 
@@ -116,7 +120,7 @@
 #        define ElfW(type) Elf64_##type
 #      endif
 #    else
-#      ifdef NETBSD
+#      if defined(NETBSD) || defined(OPENBSD)
 #        if ELFSIZE == 32
 #          define ElfW(type) Elf32_##type
 #        else
@@ -365,6 +369,7 @@ void GC_register_dynamic_libraries()
 
 #if defined(LINUX) && defined(__ELF__) || defined(SCO_ELF) || \
     (defined(FREEBSD) && defined(__ELF__)) || defined(DGUX) || \
+    (defined(OPENBSD) && defined(__ELF__)) || \
     (defined(NETBSD) && defined(__ELF__)) || defined(HURD)
 
 
@@ -476,6 +481,10 @@ GC_bool GC_register_main_static_data()
 #define HAVE_DL_ITERATE_PHDR
 #endif
 
+#if defined(OPENBSD)
+#define HAVE_DL_ITERATE_PHDR
+#endif
+
 #if defined(HAVE_DL_ITERATE_PHDR)
 
 static int GC_register_dynlib_callback(info, size, ptr)
