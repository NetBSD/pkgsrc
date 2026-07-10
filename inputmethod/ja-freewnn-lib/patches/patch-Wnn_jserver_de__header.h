$NetBSD: patch-Wnn_jserver_de__header.h,v 1.4 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wincompatible-pointer-types that are fatal on gcc14 and later
- Use proper signal handler types
- Use proper variadic arguments to print error messages

--- Wnn/jserver/de_header.h.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jserver/de_header.h
@@ -379,11 +379,11 @@ extern void error_exit ();
 #endif
 extern void log_err (const char *, ...);
 extern void log_debug (const char *, ...);
-extern RETSIGTYPE signal_hand ();
-extern RETSIGTYPE terminate_hand ();
+extern RETSIGTYPE signal_hand (int);
+extern RETSIGTYPE terminate_hand (int);
 /* error1() - For compatiblity */
 #define error1 log_debug
-extern void out ();
+extern void out (char *, ...);
 #ifdef DEBUG
 #ifdef  putwchar
 #undef  putwchar
@@ -546,7 +546,7 @@ extern unsigned int diff_sisheng (int, i
 /* snd_rcv.c */
 extern int fopen_read_cur (char *);
 extern int fopen_write_cur (char *);
-extern int fread_cur (char *, register int, register int);
+extern int fread_cur (void *, register int, register int);
 extern int xgetc_cur ();
 extern void xungetc_cur (int);
 extern void fwrite_cur (unsigned char *, int, int);
