$NetBSD: patch-lib-src_libnyquist_nyquist_cmt_midifile.c,v 1.1 2025/09/29 20:52:03 mrg Exp $

Add missing types for functions.

--- lib-src/libnyquist/nyquist/cmt/midifile.c.orig	2020-05-19 02:43:53.000000000 -0700
+++ lib-src/libnyquist/nyquist/cmt/midifile.c	2025-09-25 13:30:45.282507999 -0700
@@ -379,7 +379,7 @@
 }
 
 static void
-metaevent(type)
+metaevent(int type)
 {
         int leng = msgleng();
         char *m = msg();
@@ -509,7 +509,7 @@
 }
 
 static long
-to32bit(c1,c2,c3,c4)
+to32bit(int c1,int c2,int c3,int c4)
 {
         long value = 0L;
 
