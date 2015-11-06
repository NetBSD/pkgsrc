$NetBSD: patch-src_trace-icmp.c,v 1.1 2015/11/06 20:36:01 joerg Exp $

--- src/trace-icmp.c.orig	2015-11-06 15:58:04.000000000 +0000
+++ src/trace-icmp.c
@@ -40,19 +40,18 @@ send_echo_probe (int fd, unsigned ttl, u
 	if (plen < sizeof (struct icmp6_hdr))
 		plen = sizeof (struct icmp6_hdr);
 
-	struct
-	{
-		struct icmp6_hdr ih;
-		uint8_t payload[plen - sizeof (struct icmp6_hdr)];
-	} packet;
-	memset (&packet, 0, plen);
-
-	packet.ih.icmp6_type = ICMP6_ECHO_REQUEST;
-	packet.ih.icmp6_id = htons (getpid ());
-	packet.ih.icmp6_seq = htons ((ttl << 8) | (n & 0xff));
+	uint8_t buffer[plen];
+	struct icmp6_hdr ih;
+	memset (buffer, 0, plen);
+	memset (&ih, 0, sizeof(ih));
+
+	ih.icmp6_type = ICMP6_ECHO_REQUEST;
+	ih.icmp6_id = htons (getpid ());
+	ih.icmp6_seq = htons ((ttl << 8) | (n & 0xff));
 	(void)port;
+	memcpy(buffer, &ih, sizeof(ih));
 
-	return send_payload (fd, &packet.ih, plen, ttl);
+	return send_payload (fd, buffer, plen, ttl);
 }
 
 
