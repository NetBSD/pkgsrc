$NetBSD: patch-src_Server.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/Server.cc.orig	2007-06-07 12:32:28.000000000 +0000
+++ src/Server.cc
@@ -115,19 +115,19 @@ Server::Server (Options* opts, const cha
  * Stop the server.
  */
 Server::~Server () {
-  log(INFO, "delete server");
+  mylog(INFO, "delete server");
   stopThread();
-  log(INFO, "stop thread done");
+  mylog(INFO, "stop thread done");
   //close(sock_server);
-  log(INFO, "close socket done");
+  mylog(INFO, "close socket done");
 // STRANGE: uder linux, the recvfrom wont unblock when we  
 // close the socket if there is no timeour on the socket. 
 #if 0  
   pthread_join(thread, NULL);
-  log(INFO, "join done");
+  mylog(INFO, "join done");
 #endif  
   pthread_mutex_destroy(&lock);
-  log(INFO, "destroy mutex done");
+  mylog(INFO, "destroy mutex done");
 }
 
 /**
@@ -191,7 +191,7 @@ Server::runThread () {
   int packet_count = 0;
   fd_set sfd;
   
-  log(INFO, "waiting for the first packet..\n");
+  mylog(INFO, "waiting for the first packet..\n");
   while (1) {
   	
   	pthread_mutex_lock(&lock);	
@@ -209,12 +209,12 @@ Server::runThread () {
 
 		if (ret < 0)
 		{
-			log(WARN, "select failed\n");
+			mylog(WARN, "select failed\n");
 			exit(1);
 		}
 		else if (ret == 0)
 		{
-			log(WARN, "select timeout\n");
+			mylog(WARN, "select timeout\n");
 			continue;
 		}
 
@@ -251,16 +251,16 @@ Server::runThread () {
 
 		if (data_len > 0) {
 			if (packet_count == 0)
-				log(INFO, "Captured first packet!\n");
+				mylog(INFO, "Captured first packet!\n");
 			
 			packet_count++;
 			
-			log(DUMP, "Incoming message :");
-		  log(DUMP, "parsing.. %x %d", data, data_len);
+			mylog(DUMP, "Incoming message :");
+		  mylog(DUMP, "parsing.. %p %d", data, data_len);
 		  dumpRawData(DUMP, data, data_len);
 			
 			Reply* reply = Reply::replyFactory(data, data_len);
-			log(DUMP, "Incoming message parsed :");
+			mylog(DUMP, "Incoming message parsed :");
 			reply->dump();
 			//printf("server locking...\n");
 			pthread_mutex_lock(&lock);
@@ -297,7 +297,7 @@ Server::runThread () {
 			//printf("client id = %d\n", id);
 			
 			if (id < 0 || id >= 32)
-				log(FATAL, "bug, id can't be greater than 31");
+				mylog(FATAL, "bug, id can't be greater than 31");
 			reply->proc_id = opts->proc_id;
 			
 			//if (opts->debug)
