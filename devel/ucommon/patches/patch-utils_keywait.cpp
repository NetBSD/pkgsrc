$NetBSD: patch-utils_keywait.cpp,v 1.1 2014/01/26 04:00:19 rodent Exp $

Fix unportable cfmakeraw() for SunOS.

--- utils/keywait.cpp.orig	2014-01-04 17:31:43.000000000 +0000
+++ utils/keywait.cpp
@@ -122,7 +122,15 @@ PROGRAM_MAIN(argc, argv)
     shell::exiting(&cleanup);
 
     tcgetattr(0, &current);
+#if defined(__sun)
+    current.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+    current.c_oflag &= ~OPOST;
+    current.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+    current.c_cflag &= ~(CSIZE|PARENB);
+    current.c_cflag |= CS8;
+#else
     cfmakeraw(&current);
+#endif
     tcsetattr(0, TCSANOW, &current);
     fd_set inp;
     struct timeval tv = {0, 0};
