$NetBSD: patch-client.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- client.c.orig	2013-02-25 20:53:04.000000000 +0000
+++ client.c
@@ -37,7 +37,7 @@ usage:\n\
 
 global_t *gp_client;
 FILE *df;
-FILE *log;
+FILE *logp;
 char *host;
 int port = PORT_NUMBER;
 int protocol_version = 0;
@@ -132,7 +132,7 @@ main(argc,argv) int argc; char *argv[];
 			plog = fopen(optarg,"a");
 			break;
 		case 'l':
-			log = fopen(optarg,"a");
+			logp = fopen(optarg,"a");
 			break;
 		case 'T':
 			board = optarg;
