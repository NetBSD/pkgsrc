$NetBSD: patch-lib_mp4_rtphint.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/rtphint.c.orig	2017-09-25 14:55:37.538498204 +0000
+++ lib/mp4/rtphint.c
@@ -202,7 +202,7 @@ int quicktime_dump_hint_packet(u_char* h
 	u_char* bufPtr;
 	int i;
 
-	fprintf(stdout, "  relativeXmitTime %lu\n", ntohl(packetEntry->relativeXmitTime));
+	fprintf(stdout, "  relativeXmitTime %u\n", (unsigned)ntohl(packetEntry->relativeXmitTime));
 	fprintf(stdout, "  headerInfo %x\n", packetEntry->headerInfo);
 	fprintf(stdout, "  seqNum %u\n", ntohs(packetEntry->seqNum));
 	fprintf(stdout, "  flags %x\n", ntohs(packetEntry->flags));
@@ -317,7 +317,7 @@ int quicktime_get_packet_size(u_char* hi
 		+ (numDataEntries * sizeof(quicktime_rtp_data_entry_t));
 }
 
-int quicktime_get_hint_info(u_char* hintBuf, u_int hintBufSize, quicktime_hint_info_t* pHintInfo)
+void quicktime_get_hint_info(u_char* hintBuf, u_int hintBufSize, quicktime_hint_info_t* pHintInfo)
 {
 	quicktime_rtp_sample_t* sample = quicktime_get_hint_sample(hintBuf);
 	u_int16_t numPacketEntries = ntohs(sample->entryCount);
