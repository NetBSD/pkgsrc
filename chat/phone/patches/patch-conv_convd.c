$NetBSD: patch-conv_convd.c,v 1.2 2015/06/25 07:02:42 dholland Exp $

- Don't rely on __unused from netbsd's <cdefs.h> existing.
- Remove unused variable that causes build failure with gcc48.

--- conv/convd.c.orig	2013-01-02 23:00:43.000000000 +0000
+++ conv/convd.c
@@ -48,6 +48,10 @@
 
 #include "../common.h"
 
+#ifndef __unused
+#define __unused __attribute__((__unused__))
+#endif
+
 #ifndef lint
 #if 0
 static char __unused char RCSid[] = "Header: convd.c,v 1.1 85/10/29 14:20:06 broome Exp ";
@@ -98,7 +102,6 @@ main(int argc, char *argv[])
     int	 sl;
     int	 fds;
     int	 r;
-    int	 changed;
     static	int  new, old;
     struct	iovec iov[2];
     char	recvbuf[BUFSIZ];
@@ -113,7 +116,6 @@ main(int argc, char *argv[])
     stayaround = 1;
     currslot = -1;
     highslot = -1;
-    changed = 0;
 
     signal(SIGPIPE, SIG_IGN);  /* we'll find out soon enough */
     signal(SIGALRM, sigalrm);  /* to handle timeout */
