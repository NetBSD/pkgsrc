$NetBSD: patch-src_jprocess.c,v 1.1 2023/12/19 23:56:00 gdt Exp $

If not FreeBSD, don't use PTY

--- src/jprocess.c.orig	2004-03-18 16:39:02.000000000 +0000
+++ src/jprocess.c	2004-03-18 16:39:57.000000000 +0000
@@ -58,8 +58,10 @@
 
 #ifdef REALLY_HAVE_TERMIOS_H
 # if !defined(__os2__) && !defined(__APPLE__)
+# ifndef __FreeBSD__
 #  define USE_PTY
 # endif
+# endif
 #endif
 
 #include "buffer.h"
