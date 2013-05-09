$NetBSD: patch-src_ServerSocket.cpp,v 1.1 2013/05/09 13:56:58 joerg Exp $

--- src/ServerSocket.cpp.orig	2013-05-09 12:01:41.000000000 +0000
+++ src/ServerSocket.cpp
@@ -39,8 +39,6 @@
 using namespace std;
 using namespace lyx::support;
 
-using boost::shared_ptr;
-
 namespace lyx {
 
 // Address is the unix address for the socket.
@@ -112,7 +110,7 @@ void ServerSocket::serverCallback()
 
 	// Register the new client.
 	clients[client_fd] =
-		shared_ptr<LyXDataSocket>(new LyXDataSocket(client_fd));
+		boost::shared_ptr<LyXDataSocket>(new LyXDataSocket(client_fd));
 	theApp()->registerSocketCallback(
 		client_fd,
 		boost::bind(&ServerSocket::dataCallback,
@@ -125,7 +123,7 @@ void ServerSocket::serverCallback()
 // if the connection has been closed
 void ServerSocket::dataCallback(int fd)
 {
-	shared_ptr<LyXDataSocket> client = clients[fd];
+	boost::shared_ptr<LyXDataSocket> client = clients[fd];
 
 	string line;
 	size_t pos;
@@ -191,8 +189,8 @@ void ServerSocket::writeln(string const 
 //	lyxerr << "ServerSocket debug dump.\n"
 //	     << "fd = " << fd_ << ", address = " << address_.absFilename() << ".\n"
 //	     << "Clients: " << clients.size() << ".\n";
-//	map<int, shared_ptr<LyXDataSocket> >::const_iterator client = clients.begin();
-//	map<int, shared_ptr<LyXDataSocket> >::const_iterator end = clients.end();
+//	map<int, boost::shared_ptr<LyXDataSocket> >::const_iterator client = clients.begin();
+//	map<int, boost::shared_ptr<LyXDataSocket> >::const_iterator end = clients.end();
 //	for (; client != end; ++client)
 //		lyxerr << "fd = " << client->first << '\n';
 // }
