$NetBSD: patch-grub-core_lib_posix__wrap_sys_types.h,v 1.1 2012/07/29 21:44:13 gsutre Exp $

Include stddef rather than defining size_t to avoid conflict.

--- grub-core/lib/posix_wrap/sys/types.h.orig	2012-05-28 15:52:37.000000000 +0000
+++ grub-core/lib/posix_wrap/sys/types.h
@@ -21,7 +21,7 @@
 
 #include <grub/misc.h>
 
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__NetBSD__))
 typedef grub_size_t size_t;
 #else
 #include <stddef.h>
