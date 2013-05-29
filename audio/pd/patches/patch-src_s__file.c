$NetBSD: patch-src_s__file.c,v 1.4 2013/05/29 11:26:12 wiz Exp $

File handling under NetBSD is the same as under Linux.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

Support OpenBSD.

Support Solaris.

--- src/s_file.c.orig	2011-03-19 22:22:27.000000000 +0000
+++ src/s_file.c
@@ -36,7 +36,7 @@ int sys_defeatrt;
 t_symbol *sys_flags = &s_;
 void sys_doflags( void);
 
-#if defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(ANDROID)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(ANDROID) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
 
 static char *sys_prefbuf;
 static int sys_prefbufsize;
