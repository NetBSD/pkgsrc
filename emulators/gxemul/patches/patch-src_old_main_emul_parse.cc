$NetBSD: patch-src_old_main_emul_parse.cc,v 1.1 2020/10/07 00:43:05 thorpej Exp $

Add support for tap(4)-based networking.

--- src/old_main/emul_parse.cc.orig	2020-10-05 23:04:38.529354586 +0000
+++ src/old_main/emul_parse.cc	2020-10-05 23:04:50.653298084 +0000
@@ -197,6 +197,7 @@ static void read_one_word(FILE *f, char 
 #define	PARSESTATE_NET			2
 #define	PARSESTATE_MACHINE		3
 
+static char cur_net_tapdev[50];
 static char cur_net_ipv4net[50];
 static char cur_net_ipv4len[50];
 static char cur_net_local_port[10];
@@ -315,6 +316,7 @@ static void parse__emul(struct emul *e, 
 		    line, EXPECT_LEFT_PARENTHESIS);
 
 		/*  Default net:  */
+		strlcpy(cur_net_tapdev, "", sizeof(cur_net_tapdev));
 		strlcpy(cur_net_ipv4net, NET_DEFAULT_IPV4_MASK,
 		    sizeof(cur_net_ipv4net));
 		snprintf(cur_net_ipv4len, sizeof(cur_net_ipv4len), "%i",
@@ -391,6 +393,7 @@ static void parse__net(struct emul *e, F
 			    sizeof(cur_net_local_port));
 
 		e->net = net_init(e, NET_INIT_FLAG_GATEWAY,
+		    cur_net_tapdev[0] ? cur_net_tapdev : NULL,
 		    cur_net_ipv4net, atoi(cur_net_ipv4len),
 		    cur_net_remote, cur_net_n_remote,
 		    atoi(cur_net_local_port), NULL);
@@ -410,6 +413,7 @@ static void parse__net(struct emul *e, F
 		return;
 	}
 
+	WORD("tapdev", cur_net_tapdev);
 	WORD("ipv4net", cur_net_ipv4net);
 	WORD("ipv4len", cur_net_ipv4len);
 	WORD("local_port", cur_net_local_port);
