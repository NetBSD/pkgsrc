--- gpspipe.c-orig	Tue Dec 29 05:30:39 2020
+++ gpspipe.c	Tue Dec 29 05:32:35 2020
@@ -85,7 +85,15 @@
     memset(&newtio, 0, sizeof(newtio));

     /* make it raw */
+#if defined(__sun)
+       newtio.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+       newtio.c_oflag &= ~OPOST;
+       newtio.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+       newtio.c_cflag &= ~(CSIZE|PARENB);
+       newtio.c_cflag |= CS8;
+#else
     (void)cfmakeraw(&newtio);
+#endif
     /* set speed */
     (void)cfsetospeed(&newtio, BAUDRATE);
