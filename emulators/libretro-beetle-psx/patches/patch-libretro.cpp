$NetBSD: patch-libretro.cpp,v 1.1 2020/05/30 15:01:19 nia Exp $

libretro.cpp: In function 'int lightrec_init_mmap()':
libretro.cpp:1683:4: error: 'S_IRUSR' was not declared in this scope
    S_IRUSR | S_IWUSR);
    ^~~~~~~
libretro.cpp:1683:14: error: 'S_IWUSR' was not declared in this scope
    S_IRUSR | S_IWUSR);

--- libretro.cpp.orig	2020-05-26 17:40:28.000000000 +0000
+++ libretro.cpp
@@ -39,6 +39,7 @@
 #endif
 
 #if defined(HAVE_SHM) || defined(HAVE_ASHMEM)
+#include <sys/stat.h>
 #include <fcntl.h>
 #endif
 
