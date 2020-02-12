$NetBSD: patch-libhb_fifo.c,v 1.2 2020/02/12 13:54:56 ryoon Exp $

* On NetBSD malloc() is defined in stdlib.h.

--- libhb/fifo.c.orig	2020-01-04 16:28:06.000000000 +0000
+++ libhb/fifo.c
@@ -16,7 +16,7 @@
 #endif
 
 #ifndef SYS_DARWIN
-#if defined( SYS_FREEBSD ) || defined ( __FreeBSD__ )
+#if defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined(__NetBSD__)
 #include <stdlib.h>
 #else
 #include <malloc.h>
