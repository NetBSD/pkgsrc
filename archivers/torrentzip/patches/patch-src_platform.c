$NetBSD: patch-src_platform.c,v 1.1 2014/01/09 15:40:55 jperkin Exp $

cfmakeraw compatability for SunOS.

--- src/platform.c.orig	2005-04-17 08:36:15.000000000 +0000
+++ src/platform.c
@@ -45,7 +45,15 @@ getch (void)
 
   tcgetattr (1, &t);
   t2 = t;
+#ifdef __sun
+  t2.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+  t2.c_oflag &= ~OPOST;
+  t2.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+  t2.c_cflag &= ~(CSIZE|PARENB);
+  t2.c_cflag |= CS8;
+#else
   cfmakeraw (&t2);
+#endif
   tcsetattr (1, TCSANOW, &t2);
   fread (&c, 1, 1, stdin);
   tcsetattr (1, TCSANOW, &t);
