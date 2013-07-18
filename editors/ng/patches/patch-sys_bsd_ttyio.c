$NetBSD: patch-sys_bsd_ttyio.c,v 1.1 2013/07/18 12:07:24 joerg Exp $

--- sys/bsd/ttyio.c.orig	2013-07-18 10:06:42.000000000 +0000
+++ sys/bsd/ttyio.c
@@ -22,6 +22,7 @@
 #include	"def.h"
 
 #include	<sgtty.h>
+#include	<termios.h>
 #ifdef	ADDFUNC	/* 90.02.14  by S.Yoshida */
 #include	<signal.h>		/* 90.02.13: For SIGWINCH.	*/
 #endif	/* ADDFUNC */
