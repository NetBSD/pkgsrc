$NetBSD: patch-src_trace-tcp.c,v 1.1 2015/11/06 20:36:01 joerg Exp $

--- src/trace-tcp.c.orig	2015-11-06 15:53:03.000000000 +0000
+++ src/trace-tcp.c
@@ -51,21 +51,21 @@ send_syn_probe (int fd, unsigned ttl, un
 	if (plen < sizeof (struct tcphdr))
 		plen = sizeof (struct tcphdr);
 
-	struct
-	{
-		struct tcphdr th;
-		uint8_t payload[plen - sizeof (struct tcphdr)];
-	} packet;
-
-	memset (&packet, 0, sizeof (packet));
-	packet.th.th_sport = sport;
-	packet.th.th_dport = port;
-	packet.th.th_seq = htonl ((ttl << 24) | (n << 16) | getpid ());
-	packet.th.th_off = sizeof (packet.th) / 4;
-	packet.th.th_flags = TH_SYN | (ecn ? (TH_ECE | TH_CWR) : 0);
-	packet.th.th_win = htons (TCP_WINDOW);
+	uint8_t buffer[plen];
 
-	return send_payload (fd, &packet, plen, ttl);
+	struct tcphdr th;
+
+	memset(&th, 0, sizeof (th));
+	memset(buffer, 0, plen);
+	th.th_sport = sport;
+	th.th_dport = port;
+	th.th_seq = htonl ((ttl << 24) | (n << 16) | getpid ());
+	th.th_off = sizeof (th) / 4;
+	th.th_flags = TH_SYN | (ecn ? (TH_ECE | TH_CWR) : 0);
+	th.th_win = htons (TCP_WINDOW);
+	memcpy(buffer, &th, sizeof(th));
+
+	return send_payload (fd, buffer, plen, ttl);
 }
 
 
@@ -128,21 +128,21 @@ send_ack_probe (int fd, unsigned ttl, un
 	if (plen < sizeof (struct tcphdr))
 		plen = sizeof (struct tcphdr);
 
-	struct
-	{
-		struct tcphdr th;
-		uint8_t payload[plen - sizeof (struct tcphdr)];
-	} packet;
-
-	memset (&packet, 0, sizeof (packet));
-	packet.th.th_sport = sport;
-	packet.th.th_dport = port;
-	packet.th.th_ack = htonl ((ttl << 24) | (n << 16) | getpid ());
-	packet.th.th_off = sizeof (packet.th) / 4;
-	packet.th.th_flags = TH_ACK;
-	packet.th.th_win = htons (TCP_WINDOW);
+	uint8_t buffer[plen];
+
+	struct tcphdr th;
+
+	memset(&th, 0, sizeof (th));
+	memset(buffer, 0, plen);
+	th.th_sport = sport;
+	th.th_dport = port;
+	th.th_ack = htonl ((ttl << 24) | (n << 16) | getpid ());
+	th.th_off = sizeof (th) / 4;
+	th.th_flags = TH_ACK;
+	th.th_win = htons (TCP_WINDOW);
+	memcpy(buffer, &th, sizeof(th));
 
-	return send_payload (fd, &packet, plen, ttl);
+	return send_payload (fd, buffer, plen, ttl);
 }
 
 
