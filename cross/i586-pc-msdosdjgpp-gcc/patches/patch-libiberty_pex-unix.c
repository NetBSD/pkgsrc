$NetBSD: patch-libiberty_pex-unix.c,v 1.1 2024/03/27 14:38:33 js Exp $

This is very weird. When replacing the #include with an #error, it does
trigger. But when using the #include inside the #ifdef HAVE_FCNTL_H, open, O_*
etc. aren't defined. I suspect this file is compiled twice, with two different
config.h files.

--- libiberty/pex-unix.c.orig	2024-03-27 12:11:05.123326945 +0000
+++ libiberty/pex-unix.c
@@ -42,9 +42,7 @@ extern int errno;
 
 #include <sys/types.h>
 
-#ifdef HAVE_FCNTL_H
 #include <fcntl.h>
-#endif
 #ifdef HAVE_SYS_WAIT_H
 #include <sys/wait.h>
 #endif
