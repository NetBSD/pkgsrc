$NetBSD: patch-canuum_jhlp.c,v 1.3 2026/07/04 07:28:53 tsutsui Exp $

- disable IEXTEN when canuum puts the tty into non-canonical input mode
  for BSD systems (from uum/jhlp.c in the latest FreeWnn-1.1.1-a023)
- also fix obvious bit-clear typos for IUCLC and XCASE

--- canuum/jhlp.c.orig	2026-07-04 07:02:53.545783256 +0000
+++ canuum/jhlp.c
@@ -897,7 +897,7 @@ j_term_init ()
 #else /* !USE_LINUX_TERM */
   buf1.c_iflag &= ~(ISTRIP | INLCR | IGNCR | ICRNL | IXON);
 #ifdef IUCLC
-  buf1.c_iflag &= IUCLC;
+  buf1.c_iflag &= ~IUCLC;
 #endif
   if (flow_control)
     {
@@ -905,7 +905,10 @@ j_term_init ()
     }
   buf1.c_lflag &= ~(ECHONL | ECHOK | ECHOE | ECHO | ICANON | ISIG);
 #ifdef XCASE
-  buf1.c_lflag &= XCASE;
+  buf1.c_lflag &= ~XCASE;
+#endif
+#ifdef IEXTEN
+  buf1.c_lflag &= ~IEXTEN;
 #endif
   buf1.c_oflag = OPOST;
 #ifdef USE_TERMIOS
