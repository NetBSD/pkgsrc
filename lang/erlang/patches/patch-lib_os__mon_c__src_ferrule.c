$NetBSD: patch-lib_os__mon_c__src_ferrule.c,v 1.1 2013/06/25 10:06:34 jperkin Exp $

Avoid -Werror=return-type errors.

--- lib/os_mon/c_src/ferrule.c.orig	2013-02-25 19:21:31.000000000 +0000
+++ lib/os_mon/c_src/ferrule.c
@@ -50,7 +50,7 @@
 #define		FDS_STDIN	0
 #define		FDS_PIPE	1
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 /*	usage: ferrule ownpath */
 {
     int		i, pipe_fd;
