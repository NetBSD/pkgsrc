$NetBSD: patch-src_unixhdr.h,v 1.1 2021/08/07 12:20:17 prlw1 Exp $

There is no configure test for GWINSZ_IN_SYS_IOCTL, and ioctl() is used.

--- src/unixhdr.h.orig	2021-05-04 15:35:21.000000000 +0000
+++ src/unixhdr.h
@@ -29,9 +29,7 @@
   #endif
 #endif
           
-#if defined GWINSZ_IN_SYS_IOCTL && GWINSZ_IN_SYS_IOCTL
 #include <sys/ioctl.h>
-#endif
 
 #ifndef NO_TERM_H
   #ifndef TERM_H
