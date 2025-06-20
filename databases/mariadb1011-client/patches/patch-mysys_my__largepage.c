$NetBSD: patch-mysys_my__largepage.c,v 1.1 2025/06/20 17:04:41 nia Exp $

Fix build on illumos, via OmniOS CE.

Undefined                       first referenced
 symbol                             in file
opt_super_large_pages               ../../mysys/libmysys.a(my_largepage.c.o)

--- mysys/my_largepage.c.orig	2025-05-19 16:14:25.000000000 +0000
+++ mysys/my_largepage.c
@@ -28,6 +28,7 @@
 #endif
 
 #ifdef HAVE_SOLARIS_LARGE_PAGES
+my_bool opt_super_large_pages= 0;
 #if defined(__sun__) && defined(__GNUC__) && defined(__cplusplus) \
     && defined(_XOPEN_SOURCE)
 /* memcntl exist within sys/mman.h, but under-defines what is need to use it */
@@ -203,7 +204,6 @@ int my_init_large_pages(void)
   my_get_large_page_sizes(my_large_page_sizes);
 
 #ifdef HAVE_SOLARIS_LARGE_PAGES
-  extern my_bool opt_super_large_pages;
   /*
     tell the kernel that we want to use 4/256MB page for heap storage
     and also for the stack. We use 4 MByte as default and if the
