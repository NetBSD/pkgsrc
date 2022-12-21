$NetBSD: patch-src_telnet.c,v 1.1 2022/12/21 14:41:59 wiz Exp $

Fix compilation on char = signed char systems.

--- src/telnet.c.orig	2008-12-14 09:33:10.000000000 +0000
+++ src/telnet.c
@@ -160,7 +160,7 @@ static void sigTERM(int sig){
 #define O_AUTH		37	/* Authentication */
 #define O_NENVIRON	39	/* New Environment Option RFC1572 */
 
-static char NOPstr[2] = { IAC, NOP };
+static unsigned char NOPstr[2] = { IAC, NOP };
 
 static void sigurg(int sig)
 {	const char *ssig;
@@ -1810,7 +1810,7 @@ static int telnetonly(Connection *Conn)
 static struct { 
 	char *ne_USER;
 } clenv;
-static char doNewEnviron[] = {IAC,SB,O_NENVIRON,1,IAC,SE};
+static unsigned char doNewEnviron[] = {IAC,SB,O_NENVIRON,1,IAC,SE};
 static int getUSERenv(FILE *fc,FILE *tc,AuthInfo *au){
 	int rcc,nrcc;
 	int timeout = 15*1000;
@@ -1911,7 +1911,7 @@ int service_telnet(Connection *Conn)
 			 */
 			if( telnetonly(Conn) ){
 				write(ToC,NOPstr,2);
-				scanCommands(DtoC,CVStr(NOPstr),2);
+				scanCommands(DtoC,CVStr((char *)NOPstr),2);
 			}
 		}
 		proxy_telnet(Conn);
@@ -1927,7 +1927,7 @@ int service_telnet(Connection *Conn)
 		int dport = DFLT_PORT;
 
 		write(ToC,NOPstr,2);
-		scanCommands(DtoC,CVStr(NOPstr),2);
+		scanCommands(DtoC,CVStr((char *)NOPstr),2);
 
 		auser[0] = ahost[0] = 0;
 		DFLT_PORT = 0; /* to escape "already authorized" */
@@ -1967,7 +1967,7 @@ int service_telnet(Connection *Conn)
 	 */
 	if( PollIn(FromS,10) == 0 ){
 		write(ToC,NOPstr,2);
-		scanCommands(DtoC,CVStr(NOPstr),2);
+		scanCommands(DtoC,CVStr((char *)NOPstr),2);
 	}
 	/*
 	{	CStr(buf,3);
