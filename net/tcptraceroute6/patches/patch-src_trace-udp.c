$NetBSD: patch-src_trace-udp.c,v 1.1 2015/11/06 20:36:01 joerg Exp $

--- src/trace-udp.c.orig	2015-11-06 15:56:21.000000000 +0000
+++ src/trace-udp.c
@@ -43,25 +43,25 @@ send_udp_probe (int fd, unsigned ttl, un
 	if (plen < sizeof (struct udphdr))
 		plen = sizeof (struct udphdr);
 
-	struct
-	{
-		struct udphdr uh;
-		uint8_t payload[plen - sizeof (struct udphdr)];
-	} packet;
-	memset (&packet, 0, plen);
+	uint8_t buffer[plen];
+	struct udphdr uh;
+
+	memset (&uh, 0, sizeof(uh));
+	memset (buffer, 0, plen);
 
 	(void)n;
-	packet.uh.uh_sport = sport;
-	packet.uh.uh_dport = htons (ntohs (port) + ttl);
+	uh.uh_sport = sport;
+	uh.uh_dport = htons (ntohs (port) + ttl);
 	/* For UDP-Lite we have full checksum coverage, if only because the
 	 * IPV6_CHECKSUM setsockopt only supports full coverage. Hence
 	 * we can set coverage to the length of the packet, even though zero
 	 * would be more idiosyncrasic. */
-	packet.uh.uh_ulen = htons (plen);
+	uh.uh_ulen = htons (plen);
 	/*if (plen > sizeof (struct udphdr))
 		packet.payload[0] = (uint8_t)ttl;*/
+	memcpy(buffer, &uh, sizeof(uh));
 
-	return send_payload (fd, &packet, plen, ttl);
+	return send_payload (fd, buffer, plen, ttl);
 }
 
 
