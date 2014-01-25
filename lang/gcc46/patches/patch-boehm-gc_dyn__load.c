$NetBSD: patch-boehm-gc_dyn__load.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- boehm-gc/dyn_load.c.orig	2010-11-29 14:58:16.000000000 +0000
+++ boehm-gc/dyn_load.c
@@ -60,6 +60,7 @@
     !defined(HPUX) && !(defined(LINUX) && defined(__ELF__)) && \
     !defined(RS6000) && !defined(SCO_ELF) && !defined(DGUX) && \
     !(defined(FREEBSD) && defined(__ELF__)) && \
+    !(defined(OPENBSD) && defined(__ELF__)) && \
     !(defined(NETBSD) && defined(__ELF__)) && !defined(HURD) && \
     !defined(DARWIN)
  --> We only know how to find data segments of dynamic libraries for the
@@ -90,9 +91,9 @@
 
 #if defined(LINUX) && defined(__ELF__) || defined(SCO_ELF) || \
     (defined(FREEBSD) && defined(__ELF__)) || defined(DGUX) || \
+    (defined(OPENBSD) && defined(__ELF__)) || \
     (defined(NETBSD) && defined(__ELF__)) || defined(HURD)
 #   include <stddef.h>
-#   include <elf.h>
 #   include <link.h>
 #endif
 
@@ -106,7 +107,7 @@
 #        define ElfW(type) Elf64_##type
 #      endif
 #    else
-#      ifdef NETBSD
+#      if defined(NETBSD) || defined(OPENBSD)
 #        if ELFSIZE == 32
 #          define ElfW(type) Elf32_##type
 #        else
@@ -301,6 +302,7 @@ void GC_register_dynamic_libraries()
 
 #if defined(LINUX) && defined(__ELF__) || defined(SCO_ELF) || \
     (defined(FREEBSD) && defined(__ELF__)) || defined(DGUX) || \
+    (defined(OPENBSD) && defined(__ELF__)) || \
     (defined(NETBSD) && defined(__ELF__)) || defined(HURD)
 
 
@@ -412,6 +414,10 @@ GC_bool GC_register_main_static_data()
 #define HAVE_DL_ITERATE_PHDR
 #endif
 
+#if defined(OPENBSD)
+#define HAVE_DL_ITERATE_PHDR
+#endif
+
 #if defined(HAVE_DL_ITERATE_PHDR)
 
 static int GC_register_dynlib_callback(info, size, ptr)
