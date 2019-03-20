$NetBSD: patch-util_telnet-client.c,v 1.3 2019/03/20 16:02:10 jperkin Exp $

Provide workaround for a non-POSIX cfmakeraw call.
Uses getaddrinfo.

--- util/telnet-client.c.orig	2012-03-18 21:07:49.000000000 +0000
+++ util/telnet-client.c
@@ -9,9 +9,15 @@
  * all present and future rights to this code under copyright law. 
  */
 
+#ifdef __NetBSD__
+#define _NETBSD_SOURCE
+#endif
+#if !defined(__sun) || __STDC_VERSION__-0 < 199901L
+#define _XOPEN_SOURCE 520
 #if !defined(_POSIX_SOURCE)
 #	define _POSIX_SOURCE
 #endif
+#endif
 #if !defined(_BSD_SOURCE)
 #	define _BSD_SOURCE
 #endif
@@ -199,7 +205,15 @@ int main(int argc, char **argv) {
 	tcgetattr(STDOUT_FILENO, &orig_tios);
 	atexit(_cleanup);
 	tios = orig_tios;
+#ifdef __sun
+	tios.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+	tios.c_oflag &= ~OPOST;
+	tios.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+	tios.c_cflag &= ~(CSIZE|PARENB);
+	tios.c_cflag |= CS8;
+#else
 	cfmakeraw(&tios);
+#endif
 	tcsetattr(STDOUT_FILENO, TCSADRAIN, &tios);
 
 	/* set input echoing on by default */
