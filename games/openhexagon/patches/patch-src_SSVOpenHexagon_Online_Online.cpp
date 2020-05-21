$NetBSD: patch-src_SSVOpenHexagon_Online_Online.cpp,v 1.1 2020/05/21 08:42:57 plunky Exp $

Avoid crash after 75 seconds.

--- src/SSVOpenHexagon/Online/Online.cpp.orig	2013-07-13 23:37:47.000000000 +0000
+++ src/SSVOpenHexagon/Online/Online.cpp
@@ -143,6 +143,7 @@ namespace hg
 				TcpSocket socket;
 				Packet packet0x01, packet0x11;
 				packet0x01 << int8_t{0x01} << (string)mValidator << (float)mDifficulty << (string)mName;
+#if 0
 				socket.connect(hostIp, hostPort); socket.send(packet0x01); socket.receive(packet0x11);
 				uint8_t packetID, pass;
 				string response[2];
@@ -164,6 +165,7 @@ namespace hg
 					else log("Error: could not get scores", "Online");
 				}
 				socket.disconnect();
+#endif
 				log("Finished getting scores", "Online");
 				startGetFriendsScores(mTarget, mNames, mValidator, mDifficulty);
 				cleanUp();
