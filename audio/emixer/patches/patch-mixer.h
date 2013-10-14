$NetBSD: patch-mixer.h,v 1.1 2013/10/14 13:33:31 roy Exp $

--- mixer.h.orig	1999-12-28 00:45:52.000000000 +0000
+++ mixer.h
@@ -17,7 +17,11 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
+#ifdef __NetBSD__
+#include <soundcard.h>
+#else
 #include <sys/soundcard.h>
+#endif
 #include <signal.h>
 #include <sys/types.h>
 #include <termios.h>
