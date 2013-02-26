$NetBSD: patch-netmaj1.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- netmaj1.c.orig	2013-02-25 20:50:53.000000000 +0000
+++ netmaj1.c
@@ -41,7 +41,7 @@ int auto_stop=1;
 int play_speed=1;
 extern int tonpu;
 
-FILE *log;
+FILE *logp;
 FILE *log_server;
 FILE *plog = 0;
 callback() {}
@@ -234,7 +234,7 @@ main(argc,argv) int argc; char *argv[]; 
 			df = fopen(optarg,"w");
 			break;
 		case 'l':
-			log = fopen(optarg,"w");
+			logp = fopen(optarg,"w");
 			break;
 		case 'H':
 			tonpu = 0;
