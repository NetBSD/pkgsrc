$NetBSD: patch-Wnn_jserver_de__header.h,v 1.3 2026/06/28 06:16:27 tsutsui Exp $

- Appease -Wincompatible-pointer-types warning

--- Wnn/jserver/de_header.h.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jserver/de_header.h
@@ -546,7 +546,7 @@ extern unsigned int diff_sisheng (int, i
 /* snd_rcv.c */
 extern int fopen_read_cur (char *);
 extern int fopen_write_cur (char *);
-extern int fread_cur (char *, register int, register int);
+extern int fread_cur (void *, register int, register int);
 extern int xgetc_cur ();
 extern void xungetc_cur (int);
 extern void fwrite_cur (unsigned char *, int, int);
