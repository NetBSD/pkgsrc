$NetBSD: patch-dirmngr_dns.c,v 1.1 2019/03/27 09:42:15 jperkin Exp $

Avoid _P.

--- dirmngr/dns.c.orig	2019-03-07 12:03:15.000000000 +0000
+++ dirmngr/dns.c
@@ -5275,8 +5275,8 @@ error:
 
 
 struct dns_packet *dns_hosts_query(struct dns_hosts *hosts, struct dns_packet *Q, int *error_) {
-	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _P = { 0 };
-	struct dns_packet *P	= dns_p_init(&_P.p, 512);
+	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _Pack = { 0 };
+	struct dns_packet *P	= dns_p_init(&_Pack.p, 512);
 	struct dns_packet *A	= 0;
 	struct dns_rr rr;
 	struct dns_hosts_entry *ent;
@@ -6837,7 +6837,7 @@ unsigned dns_hints_grep(struct sockaddr
 
 
 struct dns_packet *dns_hints_query(struct dns_hints *hints, struct dns_packet *Q, int *error_) {
-	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _P = { 0 };
+	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _Pack = { 0 };
 	struct dns_packet *A, *P;
 	struct dns_rr rr;
 	char zone[DNS_D_MAXNAME + 1];
@@ -6858,7 +6858,7 @@ struct dns_packet *dns_hints_query(struc
 	else if (zlen >= sizeof zone)
 		goto toolong;
 
-	P			= dns_p_init(&_P.p, 512);
+	P			= dns_p_init(&_Pack.p, 512);
 	dns_header(P)->qr	= 1;
 
 	if ((error = dns_rr_copy(P, &rr, Q)))
@@ -8463,8 +8463,8 @@ error:
 
 
 static struct dns_packet *dns_res_glue(struct dns_resolver *R, struct dns_packet *Q) {
-	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _P = { 0 };
-	struct dns_packet *P	= dns_p_init(&_P.p, 512);
+	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _Pack = { 0 };
+	struct dns_packet *P	= dns_p_init(&_Pack.p, 512);
 	char qname[DNS_D_MAXNAME + 1];
 	size_t qlen;
 	enum dns_type qtype;
@@ -10608,9 +10608,9 @@ static void print_packet(struct dns_pack
 
 
 static int parse_packet(int argc DNS_NOTUSED, char *argv[] DNS_NOTUSED) {
-	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _P = { 0 };
+	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _Pack = { 0 };
 	union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _Q = { 0 };
-	struct dns_packet *P	= dns_p_init(&_P.p, 512);
+	struct dns_packet *P	= dns_p_init(&_Pack.p, 512);
 	struct dns_packet *Q	= dns_p_init(&_Q.p, 512);
 	enum dns_section section;
 	struct dns_rr rr;
@@ -11033,10 +11033,10 @@ static int show_hints(int argc, char *ar
 	if (0 == strcmp(how, "plain")) {
 		dns_hints_dump(hints, stdout);
 	} else {
-		union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _P = { 0 };
+		union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _Pack = { 0 };
 		struct dns_packet *query, *answer;
 
-		query	= dns_p_init(&_P.p, 512);
+		query	= dns_p_init(&_Pack.p, 512);
 
 		if ((error = dns_p_push(query, DNS_S_QUESTION, who, strlen(who), DNS_T_A, DNS_C_IN, 0, 0)))
 			panic("%s: %s", who, dns_strerror(error));
@@ -11199,8 +11199,8 @@ static int echo_port(int argc DNS_NOTUSE
 		panic("127.0.0.1:5353: %s", dns_strerror(errno));
 
 	for (;;) {
-		union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _P = { 0 };
-		struct dns_packet *pkt = dns_p_init(&_P.p, 512);
+		union { unsigned char b[dns_p_calcsize((512))]; struct dns_packet p; } _Pack = { 0 };
+		struct dns_packet *pkt = dns_p_init(&_Pack.p, 512);
 		struct sockaddr_storage ss;
 		socklen_t slen = sizeof ss;
 		ssize_t count;
