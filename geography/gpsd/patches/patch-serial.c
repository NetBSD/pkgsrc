--- serial.c-orig	Tue Dec 29 05:16:05 2020
+++ serial.c	Tue Dec 29 05:17:32 2020
@@ -178,7 +178,7 @@
     session->reawake = (time_t)0;
 }

-#if !defined(HAVE_CFMAKERAW)
+#if !defined(HAVE_CFMAKERAW) || defined(__sun)
 /*
  * Local implementation of cfmakeraw (which is not specified by
  * POSIX; see matching declaration in gpsd.h).
@@ -187,7 +187,7 @@
 void cfmakeraw(struct termios *termios_p)
 {
     termios_p->c_iflag &=
-        ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
+        ~(IMAXBEL | IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
     termios_p->c_oflag &= ~OPOST;
     termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
     termios_p->c_cflag &= ~(CSIZE | PARENB);
