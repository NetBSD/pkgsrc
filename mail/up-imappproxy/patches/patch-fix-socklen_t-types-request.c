$NetBSD: patch-fix-socklen_t-types-request.c,v 1.1 2020/04/17 11:28:02 tm Exp $

Fix socklen_t types

Richard Laager <rlaager@wiktel.com>
https://sourceforge.net/p/squirrelmail/mailman/message/35526927/

--- src/request.c.orig
+++ src/request.c
@@ -702,7 +702,7 @@
     char fullServerResponse[BUFSIZE] = "\0\0\0";
     int BytesRead;
     struct sockaddr_storage cli_addr;
-    int sockaddrlen;
+    socklen_t sockaddrlen;
     char hostaddr[INET6_ADDRSTRLEN], portstr[NI_MAXSERV];
     
     unsigned int BufLen = BUFSIZE - 1;
@@ -979,7 +979,7 @@
     ICD_Struct *conn;
     char fullServerResponse[BUFSIZE] = "\0\0\0";
     struct sockaddr_storage cli_addr;
-    int sockaddrlen;
+    socklen_t sockaddrlen;
     char hostaddr[INET6_ADDRSTRLEN], portstr[NI_MAXSERV];
 
     memset( &Server, 0, sizeof Server );
