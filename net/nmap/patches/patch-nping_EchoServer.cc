$NetBSD: patch-nping_EchoServer.cc,v 1.1 2020/03/18 17:58:43 joerg Exp $

Don't match std::bind.

--- nping/EchoServer.cc.orig	2020-03-18 16:55:31.850840039 +0000
+++ nping/EchoServer.cc
@@ -281,12 +281,12 @@ int EchoServer::nep_listen_socket(){
         server_addr6.sin6_len = sizeof(struct sockaddr_in6);
     #endif
     /* Bind to local address and the specified port */
-    if( bind(master_sd, (struct sockaddr *)&server_addr6, sizeof(server_addr6)) != 0 ){
+    if( ::bind(master_sd, (struct sockaddr *)&server_addr6, sizeof(server_addr6)) != 0 ){
         nping_warning(QT_3, "Failed to bind to source address %s. Trying to bind to port %d...", IPtoa(server_addr6.sin6_addr), port);
         /* If the bind failed for the supplied address, just try again with in6addr_any */
         if( o.spoofSource() ){
             server_addr6.sin6_addr = in6addr_any;
-            if( bind(master_sd, (struct sockaddr *)&server_addr6, sizeof(server_addr6)) != 0 ){
+            if( ::bind(master_sd, (struct sockaddr *)&server_addr6, sizeof(server_addr6)) != 0 ){
                 nping_fatal(QT_3, "Could not bind to port %d (%s).", port, strerror(errno));
             }else{ 
                 nping_print(VB_1, "Server bound to port %d", port);
@@ -319,12 +319,12 @@ int EchoServer::nep_listen_socket(){
 #endif
 
     /* Bind to local address and the specified port */
-    if( bind(master_sd, (struct sockaddr *)&server_addr4, sizeof(server_addr4)) != 0 ){
+    if( ::bind(master_sd, (struct sockaddr *)&server_addr4, sizeof(server_addr4)) != 0 ){
         nping_warning(QT_3, "Failed to bind to source address %s. Trying to bind to port %d...", IPtoa(server_addr4.sin_addr), port);
         /* If the bind failed for the supplied address, just try again with in6addr_any */
         if( o.spoofSource() ){
             server_addr4.sin_addr.s_addr=INADDR_ANY;
-            if( bind(master_sd, (struct sockaddr *)&server_addr4, sizeof(server_addr4)) != 0 ){
+            if( ::bind(master_sd, (struct sockaddr *)&server_addr4, sizeof(server_addr4)) != 0 ){
                 nping_fatal(QT_3, "Could not bind to port %d (%s).", port, strerror(errno));
             }else{
                 nping_print(VB_1, "Server bound to port %d", port);
