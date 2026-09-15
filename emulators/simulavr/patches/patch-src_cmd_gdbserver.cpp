$NetBSD: patch-src_cmd_gdbserver.cpp,v 1.3 2026/09/15 08:59:37 wiz Exp $

Avoid 'using namespace std'. This introduces a conflict between
std::byte and the local typedef.

Use BSD bind, not STL bind.

--- src/cmd/gdbserver.cpp.orig	2012-02-12 15:26:38.000000000 +0000
+++ src/cmd/gdbserver.cpp
@@ -24,7 +24,6 @@
  */
 
 #include <iostream>
-using namespace std;
 
 #include <assert.h>
 #include <stdio.h>
@@ -183,7 +182,7 @@ GdbServerSocketUnix::GdbServerSocketUnix(int port) {
     address->sin_port = htons(port);
     memset(&address->sin_addr, 0, sizeof(address->sin_addr));
 
-    if(bind(sock, (struct sockaddr *)address, sizeof(address)))
+    if(::bind(sock, (struct sockaddr *)address, sizeof(address)))
         avr_error("Can not bind socket: %s", strerror(errno));
 
     if(listen(sock, 1) < 0)
@@ -310,7 +309,7 @@ GdbServer::GdbServer(AvrDevice *c, int _port, int debu
 }
 
 //make the instance of static list of all gdb servers here
-vector<GdbServer*> GdbServer::allGdbServers;
+std::vector<GdbServer*> GdbServer::allGdbServers;
 
 GdbServer::~GdbServer() {
     server->Close();
@@ -1439,7 +1438,7 @@ void GdbServer::IdleStep() {
 
 void GdbServer::IdleStep() {
     int gdbRet=gdb_receive_and_process_packet(GDB_BLOCKING_OFF);
-    cout << "IdleStep Instance" << this << " RunMode:" << dec << runMode << endl;
+    std::cout << "IdleStep Instance" << this << " RunMode:" << std::dec << runMode << std::endl;
 
     if (lastCoreStepFinished) {
         switch(gdbRet) {
@@ -1459,7 +1458,7 @@ void GdbServer::IdleStep() {
                 break;
 
             default:
-                cout << "wondering" << endl;
+                std::cout << "wondering" << std::endl;
         }
     }
 }
@@ -1516,7 +1515,7 @@ int GdbServer::InternalStep(bool &untilCoreStepFinishe
             if(!leave) { //we can�t leave the loop so we have to request the other gdb instances now!
                 // step through all gdblist members WITHOUT my self!
                 //cout << "we do not leave and check for gdb events" << endl;
-                vector<GdbServer*>::iterator ii;
+                std::vector<GdbServer*>::iterator ii;
                 for (ii=allGdbServers.begin(); ii!=allGdbServers.end(); ii++) {
                     if (*ii!=this) { //run other instances but not me 
                         (*ii)->IdleStep();
