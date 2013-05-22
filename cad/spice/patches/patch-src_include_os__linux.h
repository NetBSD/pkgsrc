$NetBSD: patch-src_include_os__linux.h,v 1.1 2013/05/22 07:44:04 sbd Exp $

--- src/include/os_linux.h.orig	2013-05-22 07:03:07.803730428 +0000
+++ src/include/os_linux.h
@@ -0,0 +1,30 @@
+/**********
+Copyright 1990 Regents of the University of California.  All rights reserved.
+**********/
+
+/*
+ *	Linux systems
+ */
+
+#include "os_unix.h"
+
+#define HAS_ATRIGH		/* acosh( ), asinh( ), atanh( )         */
+#define HAS_FTIME		/* ftime( ), <times.h>			*/
+#define HAS_TERMCAP		/* tgetxxx( )				*/
+#define HAS_VFORK		/* BSD-ism, should not be necessary	*/
+#define HAS_BCOPY		/* bcopy( ), bzero( )			*/
+#define HAS_BSDRANDOM		/* srandom( ) and random( )		*/
+#define HAS_SYSVTTY		/* <termio.h>				*/
+#define HAS_BSDDIRS		/* <sys/dir.h>				*/
+#define HAS_BSDRUSAGE		/* getrusage( )				*/
+#define HAS_BSDRLIMIT		/* getrlimit( )				*/
+#define HAS_DUP2
+#define HAS_GETWD		/* getwd(buf)				*/
+
+#define HAS_STDLIB
+#define HAS_FLOAT_H		/* float.h				*/
+#define HAS_BSDTIME		/* gettimeofday( ) return time		*/
+#define HAS_STRCHR		/* strchr( ) instead of index( )	*/
+#define HAS_LIMITS_H		/* limits.h exists			*/
+#define HAS_INTWAITSTATUS	/* wait(int *status)			*/
+/*#define HAS_GNUREADLINE*/		/* compile in readline support		*/
