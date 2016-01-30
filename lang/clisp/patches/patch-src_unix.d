$NetBSD: patch-src_unix.d,v 1.1 2016/01/30 00:38:15 wiz Exp $

Fix prototype to match the one on NetBSD.

--- src/unix.d.orig	2010-04-27 20:40:10.000000000 +0000
+++ src/unix.d
@@ -145,7 +145,7 @@ extern_C char* strerror (int errnum);
 /* paging control */
 #ifdef HAVE_VADVISE
   #include <sys/vadvise.h> /* control codes */
-  extern_C void vadvise (int param); /* paging system control, see VADVISE(2) */
+  extern_C int vadvise (int param); /* paging system control, see VADVISE(2) */
 #endif
 /* use madvise() ?? */
 /* used by SPVW */
