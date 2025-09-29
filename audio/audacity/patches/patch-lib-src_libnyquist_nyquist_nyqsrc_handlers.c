$NetBSD: patch-lib-src_libnyquist_nyquist_nyqsrc_handlers.c,v 1.1 2025/09/29 20:52:04 mrg Exp $

Add missing types for functions.

--- lib-src/libnyquist/nyquist/nyqsrc/handlers.c.orig	2020-05-19 02:43:53.000000000 -0700
+++ lib-src/libnyquist/nyquist/nyqsrc/handlers.c	2025-09-25 13:32:12.586486909 -0700
@@ -6,7 +6,7 @@
 
 /* note -- a simple way to make a midi note on channel 1 */
 /**/
-void note(pitch, dur)
+void note(int pitch, int dur)
 {
 }
 
