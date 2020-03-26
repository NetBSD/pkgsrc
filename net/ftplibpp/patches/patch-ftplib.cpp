$NetBSD: patch-ftplib.cpp,v 1.1 2020/03/26 02:30:27 joerg Exp $

--- ftplib.cpp.orig	2020-03-25 15:24:48.938447059 +0000
+++ ftplib.cpp
@@ -766,7 +766,7 @@ int ftplib::FtpOpenPort(netbuf *nControl
     }
 
 	sin.in.sin_port = 0;
-	if (bind(sData, &sin.sa, sizeof(sin)) == -1)
+	if (::bind(sData, &sin.sa, sizeof(sin)) == -1)
 	{
 	    perror("bind");
 	    net_close(sData);
