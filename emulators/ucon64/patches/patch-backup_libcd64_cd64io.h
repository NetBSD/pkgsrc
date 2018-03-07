$NetBSD: patch-backup_libcd64_cd64io.h,v 1.1 2018/03/07 12:34:55 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- backup/libcd64/cd64io.h.orig	2015-11-29 19:31:07.000000000 +0000
+++ backup/libcd64/cd64io.h
@@ -34,10 +34,10 @@ int cd64_xfer_portdev(struct cd64_t *cd6
 #if defined __linux__ && (defined __i386__ || defined __x86_64__)
 #include <sys/io.h>
 #endif
-#ifdef __OpenBSD__
+#if (defined __OpenBSD__ || defined __NetBSD__) && (defined __i386__ || defined __x86_64__)
 #include <sys/types.h>
 #include <machine/sysarch.h>
-#include <i386/pio.h>
+#include <machine/pio.h>
 /* pio.h defines several I/O functions & macros, including the macros inb() and
  * outb(). This shows that using a bit of inline assembly is not such a bad idea
  * at all. */
