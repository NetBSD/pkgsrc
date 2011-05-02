$NetBSD: patch-src_knockd.c,v 1.1 2011/05/02 10:11:34 adam Exp $

Use correct network structures.
Re-open log file on SIGHUP.

--- src/knockd.c.orig	2005-06-27 05:11:34.000000000 +0000
+++ src/knockd.c
@@ -28,18 +28,20 @@
 #include <ctype.h>
 #include <string.h>
 #include <fcntl.h>
+#include <sys/param.h>
+#include <sys/time.h>
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <sys/wait.h>
+#include <sys/ioctl.h>
+#include <net/if.h>
 #include <netinet/in.h>
+#include <netinet/in_systm.h>
 #include <netinet/if_ether.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
 #include <netinet/udp.h>
 #include <netinet/ip_icmp.h>
-#include <net/if.h>
-#include <bits/time.h>
-#include <sys/socket.h>
-#include <sys/types.h>
-#include <sys/wait.h>
-#include <sys/ioctl.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <getopt.h>
@@ -193,7 +195,7 @@ int main(int argc, char **argv)
 		}
 	}
 
-	cap = pcap_open_live(o_int, 65535, 0, 0, pcapErr);
+	cap = pcap_open_live(o_int, 65535, 0, 1000, pcapErr);
 	if(strlen(pcapErr)) {
 		fprintf(stderr, "could not open %s: %s\n", o_int, pcapErr);
 	}
@@ -371,7 +373,18 @@ void read_cfg(int signum)
 	}
 	list_free(doors);
 
+	if(logfd) {
+		fclose(logfd);
+		logfd = NULL;
+	}
 	parseconfig(o_cfg);
+	if(strlen(o_logfile)) {
+		/* open the log file */
+		logfd = fopen(o_logfile, "a");
+		if(logfd == NULL) {
+			perror("warning: cannot open logfile");
+		}
+	}
 	return;
 }
 
@@ -1161,8 +1174,8 @@ int exec_cmd(char* command, char* name){
 void sniff(u_char* arg, const struct pcap_pkthdr* hdr, const u_char* packet)
 {
 	/* packet structs */
-	struct ethhdr* eth = NULL;
-	struct iphdr* ip   = NULL;
+	struct ether_header* eth = NULL;
+	struct ip* ip   = NULL;
 	struct tcphdr* tcp = NULL;
 	struct udphdr* udp = NULL;
 	char proto[8];
@@ -1179,23 +1192,23 @@ void sniff(u_char* arg, const struct pca
 	knocker_t *attempt = NULL;
 
 	if(lltype == DLT_EN10MB) {
-		eth = (struct ethhdr*)packet;
-		if(ntohs(eth->h_proto) != ETH_P_IP) {
+		eth = (struct ether_header*)packet;
+		if(ntohs(eth->ether_type) != ETHERTYPE_IP) {
 			return;
 		}
-		ip = (struct iphdr*)(packet + sizeof(struct ethhdr));
+		ip = (struct ip*)(packet + sizeof(struct ether_header));
 	} else if(lltype == DLT_LINUX_SLL) {
-		ip = (struct iphdr*)((u_char*)packet + 16);
+		ip = (struct ip*)((u_char*)packet + 16);
 	} else if(lltype == DLT_RAW) {
-		ip = (struct iphdr*)((u_char*)packet);
+		ip = (struct ip*)((u_char*)packet);
 	}
 	
-	if(ip->version != 4) {
+	if(ip->ip_v != 4) {
 		/* no IPv6 yet */
 		dprint("packet is not IPv4, ignoring...\n");
 		return;
 	}
-	if(ip->protocol == IPPROTO_ICMP) {
+	if(ip->ip_p == IPPROTO_ICMP) {
 		/* we don't do ICMP */
 		return;
 	}
@@ -1207,23 +1220,23 @@ void sniff(u_char* arg, const struct pca
 		fprintf(stderr, "error: could not understand IP address: %s\n", myip);
 		return;
 	}
-	if(ip->daddr != inaddr.s_addr) {
+	if(ip->ip_dst.s_addr != inaddr.s_addr) {
 		dprint("packet destined for another host, ignoring...\n");
 		return;
 	}
 	
 	sport = dport = 0;
-	if(ip->protocol == IPPROTO_TCP) {
+	if(ip->ip_p == IPPROTO_TCP) {
 		strncpy(proto, "tcp", sizeof(proto));
-		tcp = (struct tcphdr*)((u_char*)ip + (ip->ihl * 4));
-		sport = ntohs(tcp->source);
-		dport = ntohs(tcp->dest);
+		tcp = (struct tcphdr*)((u_char*)ip + (ip->ip_hl * 4));
+		sport = ntohs(tcp->th_sport);
+		dport = ntohs(tcp->th_dport);
 	}
-	if(ip->protocol == IPPROTO_UDP) {
+	if(ip->ip_p == IPPROTO_UDP) {
 		strncpy(proto, "udp", sizeof(proto));
-		udp = (struct udphdr*)((u_char*)ip + (ip->ihl * 4));
-		sport = ntohs(udp->source);
-		dport = ntohs(udp->dest);
+		udp = (struct udphdr*)((u_char*)ip + (ip->ip_hl * 4));
+		sport = ntohs(udp->uh_sport);
+		dport = ntohs(udp->uh_dport);
 	}
 
 	/* get the date/time */
@@ -1234,10 +1247,10 @@ void sniff(u_char* arg, const struct pca
 			pkt_tm->tm_sec);
 
 	/* convert IPs from binary to string */
-	inaddr.s_addr = ip->saddr;
+	inaddr.s_addr = ip->ip_src.s_addr;
 	strncpy(srcIP, inet_ntoa(inaddr), sizeof(srcIP)-1);
 	srcIP[sizeof(srcIP)-1] = '\0';
-	inaddr.s_addr = ip->daddr;
+	inaddr.s_addr = ip->ip_dst.s_addr;
 	strncpy(dstIP, inet_ntoa(inaddr), sizeof(dstIP)-1);
 	dstIP[sizeof(dstIP)-1] = '\0';
 
@@ -1297,69 +1310,69 @@ void sniff(u_char* arg, const struct pca
 		/* if tcp, check the flags to ignore the packets we don't want
 		 * (don't even use it to cancel sequences)
 		 */
-		if(ip->protocol == IPPROTO_TCP) {
+		if(ip->ip_p == IPPROTO_TCP) {
 			if(attempt->door->flag_fin != DONT_CARE) {
-				if(attempt->door->flag_fin == SET && tcp->fin != 1) {
+				if(attempt->door->flag_fin == SET && !(tcp->th_flags & TH_FIN)) {
 					dprint("packet is not FIN, ignoring...\n");
 					flagsmatch = 0;
 				}
-				if(attempt->door->flag_fin == NOT_SET && tcp->fin == 1) {
+				if(attempt->door->flag_fin == NOT_SET && (tcp->th_flags & TH_FIN)) {
 					dprint("packet is not !FIN, ignoring...\n");
 					flagsmatch = 0;
 				}
 			}
 			if(attempt->door->flag_syn != DONT_CARE) {
-				if(attempt->door->flag_syn == SET && tcp->syn != 1) {
+				if(attempt->door->flag_syn == SET && !(tcp->th_flags & TH_SYN)) {
 					dprint("packet is not SYN, ignoring...\n");
 					flagsmatch = 0;
 				}
-				if(attempt->door->flag_syn == NOT_SET && tcp->syn == 1) {
+				if(attempt->door->flag_syn == NOT_SET && (tcp->th_flags & TH_SYN)) {
 					dprint("packet is not !SYN, ignoring...\n");
 					flagsmatch = 0;
 				}
 			}
 			if(attempt->door->flag_rst != DONT_CARE) {
-				if(attempt->door->flag_rst == SET && tcp->rst != 1) {
+				if(attempt->door->flag_rst == SET && !(tcp->th_flags & TH_RST)) {
 					dprint("packet is not RST, ignoring...\n");
 					flagsmatch = 0;
 				}
-				if(attempt->door->flag_rst == NOT_SET && tcp->rst == 1) {
+				if(attempt->door->flag_rst == NOT_SET && (tcp->th_flags & TH_RST)) {
 					dprint("packet is not !RST, ignoring...\n");
 					flagsmatch = 0;
 				}
 			}
 			if(attempt->door->flag_psh != DONT_CARE) {
-				if(attempt->door->flag_psh == SET && tcp->psh != 1) {
+				if(attempt->door->flag_psh == SET && !(tcp->th_flags & TH_PUSH)) {
 					dprint("packet is not PSH, ignoring...\n");
 					flagsmatch = 0;
 				}
-				if(attempt->door->flag_psh == NOT_SET && tcp->psh == 1) {
+				if(attempt->door->flag_psh == NOT_SET && (tcp->th_flags & TH_PUSH)) {
 					dprint("packet is not !PSH, ignoring...\n");
 					flagsmatch = 0;
 				}
 			}
 			if(attempt->door->flag_ack != DONT_CARE) {
-				if(attempt->door->flag_ack == SET && tcp->ack != 1) {
+				if(attempt->door->flag_ack == SET && !(tcp->th_flags & TH_ACK)) {
 					dprint("packet is not ACK, ignoring...\n");
 					flagsmatch = 0;
 				}
-				if(attempt->door->flag_ack == NOT_SET && tcp->ack == 1) {
+				if(attempt->door->flag_ack == NOT_SET && (tcp->th_flags & TH_ACK)) {
 					dprint("packet is not !ACK, ignoring...\n");
 					flagsmatch = 0;
 				}
 			}
 			if(attempt->door->flag_urg != DONT_CARE) {
-				if(attempt->door->flag_urg == SET && tcp->urg != 1) {
+				if(attempt->door->flag_urg == SET && !(tcp->th_flags & TH_URG)) {
 					dprint("packet is not URG, ignoring...\n");
 					flagsmatch = 0;
 				}
-				if(attempt->door->flag_urg == NOT_SET && tcp->urg == 1) {
+				if(attempt->door->flag_urg == NOT_SET && (tcp->th_flags & TH_URG)) {
 					dprint("packet is not !URG, ignoring...\n");
 					flagsmatch = 0;
 				}
 			}
 		}
-		if(flagsmatch && ip->protocol == attempt->door->protocol[attempt->stage] &&
+		if(flagsmatch && ip->ip_p == attempt->door->protocol[attempt->stage] &&
 				dport == attempt->door->sequence[attempt->stage]) {
 			/* level up! */
 			attempt->stage++;
@@ -1451,34 +1464,34 @@ void sniff(u_char* arg, const struct pca
 		for(lp = doors; lp; lp = lp->next) {
 			opendoor_t *door = (opendoor_t*)lp->data;
 			/* if we're working with TCP, try to match the flags */
-			if(ip->protocol == IPPROTO_TCP){
+			if(ip->ip_p == IPPROTO_TCP){
 				if(door->flag_fin != DONT_CARE) {
-					if(door->flag_fin == SET && tcp->fin != 1) {dprint("packet is not FIN, ignoring...\n");continue;}
-					if(door->flag_fin == NOT_SET && tcp->fin == 1) {dprint("packet is not !FIN, ignoring...\n");continue;}
+					if(door->flag_fin == SET && !(tcp->th_flags & TH_FIN)) {dprint("packet is not FIN, ignoring...\n");continue;}
+					if(door->flag_fin == NOT_SET && (tcp->th_flags & TH_FIN)) {dprint("packet is not !FIN, ignoring...\n");continue;}
 				}
 				if(door->flag_syn != DONT_CARE) {
-					if(door->flag_syn == SET && tcp->syn != 1) {dprint("packet is not SYN, ignoring...\n");continue;}
-					if(door->flag_syn == NOT_SET && tcp->syn == 1) {dprint("packet is not !SYN, ignoring...\n");continue;}
+					if(door->flag_syn == SET && !(tcp->th_flags & TH_SYN)) {dprint("packet is not SYN, ignoring...\n");continue;}
+					if(door->flag_syn == NOT_SET && (tcp->th_flags & TH_SYN)) {dprint("packet is not !SYN, ignoring...\n");continue;}
 				}
 				if(door->flag_rst != DONT_CARE) {
-					if(door->flag_rst == SET && tcp->rst != 1) {dprint("packet is not RST, ignoring...\n");continue;}
-					if(door->flag_rst == NOT_SET && tcp->rst == 1) {dprint("packet is not !RST, ignoring...\n");continue;}
+					if(door->flag_rst == SET && !(tcp->th_flags & TH_RST)) {dprint("packet is not RST, ignoring...\n");continue;}
+					if(door->flag_rst == NOT_SET && (tcp->th_flags & TH_RST)) {dprint("packet is not !RST, ignoring...\n");continue;}
 				}
 				if(door->flag_psh != DONT_CARE) {
-					if(door->flag_psh == SET && tcp->psh != 1) {dprint("packet is not PSH, ignoring...\n");continue;}
-					if(door->flag_psh == NOT_SET && tcp->psh == 1) {dprint("packet is not !PSH, ignoring...\n");continue;}
+					if(door->flag_psh == SET && !(tcp->th_flags & TH_PUSH)) {dprint("packet is not PSH, ignoring...\n");continue;}
+					if(door->flag_psh == NOT_SET && (tcp->th_flags & TH_PUSH)) {dprint("packet is not !PSH, ignoring...\n");continue;}
 				}
 				if(door->flag_ack != DONT_CARE) {
-					if(door->flag_ack == SET && tcp->ack != 1) {dprint("packet is not ACK, ignoring...\n");continue;}
-					if(door->flag_ack == NOT_SET && tcp->ack == 1) {dprint("packet is not !ACK, ignoring...\n");continue;}
+					if(door->flag_ack == SET && !(tcp->th_flags & TH_ACK)) {dprint("packet is not ACK, ignoring...\n");continue;}
+					if(door->flag_ack == NOT_SET && (tcp->th_flags & TH_ACK)) {dprint("packet is not !ACK, ignoring...\n");continue;}
 				}
 				if(door->flag_urg != DONT_CARE) {
-					if(door->flag_urg == SET && tcp->urg != 1) {dprint("packet is not URG, ignoring...\n");continue;}
-					if(door->flag_urg == NOT_SET && tcp->urg == 1) {dprint("packet is not !URG, ignoring...\n");continue;}
+					if(door->flag_urg == SET && !(tcp->th_flags & TH_URG)) {dprint("packet is not URG, ignoring...\n");continue;}
+					if(door->flag_urg == NOT_SET && (tcp->th_flags & TH_URG)) {dprint("packet is not !URG, ignoring...\n");continue;}
 				}
 			}
 
-			if(ip->protocol == door->protocol[0] && dport == door->sequence[0]) {
+			if(ip->ip_p == door->protocol[0] && dport == door->sequence[0]) {
 				struct hostent *he;
 				/* create a new entry */
 				attempt = (knocker_t*)malloc(sizeof(knocker_t));
@@ -1490,7 +1503,7 @@ void sniff(u_char* arg, const struct pca
 				strcpy(attempt->src, srcIP);
 				/* try a reverse lookup if enabled  */
 				if (o_lookup) {
-					inaddr.s_addr = ip->saddr;
+					inaddr.s_addr = ip->ip_src.s_addr;
 					he = gethostbyaddr((void *)&inaddr, sizeof(inaddr), AF_INET);
 					if(he) {
 						attempt->srchost = strdup(he->h_name);
