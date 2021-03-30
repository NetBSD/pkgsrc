$NetBSD: patch-rtunes_rtunes.c,v 1.1 2021/03/30 12:01:04 nia Exp $

Merge fixes from https://github.com/erincandescent/rtunes

--- rtunes/rtunes.c.orig	2008-02-10 11:51:02.000000000 +0000
+++ rtunes/rtunes.c
@@ -25,8 +25,11 @@
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <string.h>
 #include <unistd.h>
+#include <endian.h>
+#include <errno.h>
 
 #include "config.h"
 #include "extern.h"
@@ -65,7 +68,7 @@ usage(void)
 {
 	extern char	*__progname;
 
-	fprintf(stderr, "usage: %s [-46] [-f configfile] [-h host] <file(s)>\n",
+	fprintf(stderr, "usage: %s [-46] [-f configfile] [-h host] [-p port] <file(s)>\n",
 	    __progname);
 
 	exit(1);
@@ -175,7 +178,9 @@ main(int argc, char *argv[])
 {
 	size_t		 a, e;
 	ssize_t		 nread;
-	int		 i, r, s, ch, fd, raw = 0, sample;
+	long 		 parsedn;
+	int		 port = AIRPORT;
+	int		 i, r, ch, fd, raw = 0, sample;
 	char		 cwd[1024];
 	unsigned char	 bufraw[4096 * 2 * 2], bufala[(4096 * 2 * 2) + 3];
 	unsigned char	*buf;
@@ -184,7 +189,7 @@ main(int argc, char *argv[])
 	struct stsc	*c;
 
 	/* get command line options */
-	while ((ch = getopt(argc, argv, "46f:h:")) != -1) {
+	while ((ch = getopt(argc, argv, "46f:h:p:y")) != -1) {
 		switch (ch) {
 		case '4':
 			if (ai_family != PF_UNSPEC)
@@ -202,6 +207,13 @@ main(int argc, char *argv[])
 		case 'h':
 			host = optarg;
 			break;
+		case 'p':
+			errno = 0;
+			parsedn = strtol(optarg, NULL, 0);
+			if (parsedn < 0 || parsedn > UINT16_MAX || errno != 0)
+				errx(1, "Invalid port number");
+			port = (int)parsedn;
+			break;
 		default:
 			usage();
 		}
@@ -220,7 +232,7 @@ main(int argc, char *argv[])
 		errx(1, "Can't get local hosts IP address");
 
 	/* connect airport rtsp port */
-	if ((sfd_rtsp = sys_connect(host, AIRPORT)) == -1)
+	if ((sfd_rtsp = sys_connect(host, port)) == -1)
 		err(1, "Connect rtsp port");
 
 	/* rtsp connection sequence */
@@ -325,7 +337,7 @@ main(int argc, char *argv[])
 
 			e = cipher_aes_sendsample(buf, nread);
 
-			s = sys_write(sfd_stream, buf, e);
+			(void)sys_write(sfd_stream, buf, e);
 
 			free(buf);
 		}
@@ -354,7 +366,7 @@ main(int argc, char *argv[])
 
 		e = cipher_aes_sendsample(buf, a);
 
-		s = sys_write(sfd_stream, buf, e);
+		(void)sys_write(sfd_stream, buf, e);
 
 		free(buf);
 	}
