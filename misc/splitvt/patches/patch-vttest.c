$NetBSD: patch-vttest.c,v 1.1 2013/07/19 12:54:58 joerg Exp $

--- vttest.c.orig	2013-07-19 10:26:29.000000000 +0000
+++ vttest.c
@@ -15,6 +15,7 @@
 #include	<sys/types.h>
 #include	<stdio.h>
 #include	<fcntl.h>
+#include        <termios.h> 
 #ifdef HAVE_TERMIO_H 
 #include        <termio.h> 
 #else 
