$NetBSD: patch-cli-session.c,v 1.1 2023/12/20 17:09:36 wiz Exp $

Terrapin fix
https://github.com/mkj/dropbear/commit/6e43be5c7b99dbee49dc72b6f989f29fdd7e9356

--- cli-session.c.orig	2022-11-14 14:30:00.000000000 +0000
+++ cli-session.c
@@ -46,6 +46,7 @@ static void cli_finished(void) ATTRIB_NO
 static void recv_msg_service_accept(void);
 static void cli_session_cleanup(void);
 static void recv_msg_global_request_cli(void);
+static void cli_algos_initialise(void);
 
 struct clientsession cli_ses; /* GLOBAL */
 
@@ -117,6 +118,7 @@ void cli_session(int sock_in, int sock_o
 	}
 
 	chaninitialise(cli_chantypes);
+	cli_algos_initialise();
 
 	/* Set up cli_ses vars */
 	cli_session_init(proxy_cmd_pid);
@@ -487,3 +489,12 @@ void cli_dropbear_log(int priority, cons
 	fflush(stderr);
 }
 
+static void cli_algos_initialise(void) {
+	algo_type *algo;
+	for (algo = sshkex; algo->name; algo++) {
+		if (strcmp(algo->name, SSH_STRICT_KEX_S) == 0) {
+			algo->usable = 0;
+		}
+	}
+}
+
