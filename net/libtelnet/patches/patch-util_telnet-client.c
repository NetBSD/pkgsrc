$NetBSD: patch-util_telnet-client.c,v 1.1 2016/04/11 11:32:22 fhajny Exp $

Provide workaround for a non-POSIX cfmakeraw call.

--- util/telnet-client.c.orig	2012-03-18 21:07:49.000000000 +0000
+++ util/telnet-client.c
@@ -199,7 +199,15 @@ int main(int argc, char **argv) {
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
