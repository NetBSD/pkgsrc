$NetBSD: patch-src_nntplib.c,v 1.1 2023/01/25 18:06:41 micha Exp $

Adjust s_close() to close() because of move from stdio to own buffer
implementation.

From upstream:
news://news.tin.org/mailman.1265.1672300926.1791.tin-dev@tin.org

--- src/nntplib.c	2022-12-25 11:00:37 +0000
+++ src/nntplib.c	2022-12-29 07:56:58 +0000
@@ -523,7 +523,7 @@
 		my_fprintf(stderr, _(txt_connection_to), (char *) inet_ntoa(sock_in.sin_addr));
 		perror("");
 #			endif /* HAVE_INET_NTOA */
-		(void) s_close(s);
+		(void) close(s);
 	}
 
 	if (x < 0) {
@@ -552,7 +552,7 @@
 	if (connect(s, (struct sockaddr *) &sock_in) < 0) {
 		save_errno = errno;
 		perror("connect");
-		(void) s_close(s);
+		(void) close(s);
 		return -save_errno;
 	}
 
@@ -571,7 +571,7 @@
 	if (connect(s, (struct sockaddr *) &sock_in, sizeof(sock_in)) < 0) {
 		save_errno = errno;
 		perror("connect");
-		(void) s_close(s);
+		(void) close(s);
 		return -save_errno;
 	}
 
@@ -723,7 +723,7 @@
 
 	if (connect(s, (struct sockaddr *) &sdn, sizeof(sdn)) < 0) {
 		nerror("connect");
-		s_close(s);
+		close(s);
 		return -1;
 	}
 
