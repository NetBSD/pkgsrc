$NetBSD: patch-channels_chan__unistim.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- channels/chan_unistim.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ channels/chan_unistim.c
@@ -984,7 +984,7 @@ static int get_to_address(int fd, struct
 	memcpy(&toAddr->sin_addr, &ip_msg.address, sizeof(struct in_addr));
 	return err;
 #else
-	memcpy(&toAddr, &public_ip, sizeof(&toAddr));
+	memcpy(toAddr, &public_ip, sizeof(struct sockaddr_in));
 	return 0;
 #endif
 }
