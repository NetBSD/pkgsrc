$NetBSD: patch-conv_convd.c,v 1.3 2017/02/07 23:55:05 joerg Exp $

- Don't rely on __unused from netbsd's <cdefs.h> existing.
- Remove unused variable that causes build failure with gcc48.
- Add explicit casts if the constants are not value preserved
  on signed char platforms.

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
@@ -357,7 +359,7 @@ intro(int fd)
     char     sc;		/* used for slot number selection */
 
     /* tell user not to update screen until done with intro */
-    sc = META | UPDATE | 00;	
+    sc = (char)(META | UPDATE | 00);
     write(fd, &sc, 1);
 
     /* first go through and add all the windows */
@@ -404,7 +406,7 @@ intro(int fd)
     }
 
     /* now he can update the screen */
-    sc = META | UPDATE | 01;
+    sc = (char)(META | UPDATE | 01);
     write(fd, &sc, 1);
 }
 
