$NetBSD: patch-src_CrossPlatform_vm__alloc.cpp,v 1.1 2021/01/14 02:47:39 nat Exp $

Fix "Not enough memory" error on startup on NetBSD.

--- src/CrossPlatform/vm_alloc.cpp.orig	2019-04-05 05:12:49.000000000 +0000
+++ src/CrossPlatform/vm_alloc.cpp
@@ -86,7 +86,7 @@ typedef unsigned long vm_uintptr_t;
 #define MAP_EXTRA_FLAGS (MAP_32BIT)
 
 #ifdef HAVE_MMAP_VM
-#if (defined(__linux__) && defined(__i386__)) || defined(__FreeBSD__) || HAVE_LINKER_SCRIPT
+#if (defined(__linux__) && defined(__i386__)) || defined(__NetBSD__) || defined(__FreeBSD__) || HAVE_LINKER_SCRIPT
 /* Force a reasonnable address below 0x80000000 on x86 so that we
    don't get addresses above when the program is run on AMD64.
    NOTE: this is empirically determined on Linux/x86.  */
