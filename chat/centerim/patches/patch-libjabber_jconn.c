$NetBSD: patch-libjabber_jconn.c,v 1.1 2013/03/02 18:20:19 joerg Exp $

--- libjabber/jconn.c.orig	2013-03-01 12:39:48.000000000 +0000
+++ libjabber/jconn.c
@@ -824,7 +824,7 @@ void *jabber_recieve_file_fd(void *arg)
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 	 
 	recv( sock, buff, SEND_BUF, 0 );
@@ -833,7 +833,7 @@ void *jabber_recieve_file_fd(void *arg)
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 	 
 //socks5 bytestream packet	 
@@ -851,7 +851,7 @@ void *jabber_recieve_file_fd(void *arg)
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 	recv( sock, buff, 47, 0 );
 	if( buff[0] != 0x05 || buff[3] != 0x03 )
@@ -859,7 +859,7 @@ void *jabber_recieve_file_fd(void *arg)
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 
 
