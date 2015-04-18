$NetBSD: patch-utils_keywait.cpp,v 1.2 2015/04/18 02:43:24 rodent Exp $

Fix unportable cfmakeraw() for SunOS.

--- utils/keywait.cpp.orig	2015-03-24 23:42:51.000000000 +0000
+++ utils/keywait.cpp
@@ -123,7 +123,15 @@ int main(int argc, char **argv)
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
