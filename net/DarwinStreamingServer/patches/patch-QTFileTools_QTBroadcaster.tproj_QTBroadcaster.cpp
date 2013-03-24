$NetBSD: patch-QTFileTools_QTBroadcaster.tproj_QTBroadcaster.cpp,v 1.1 2013/03/24 16:51:07 joerg Exp $

--- QTFileTools/QTBroadcaster.tproj/QTBroadcaster.cpp.orig	2013-03-24 12:37:12.000000000 +0000
+++ QTFileTools/QTBroadcaster.tproj/QTBroadcaster.cpp
@@ -201,7 +201,7 @@ int main(int argc, char *argv[]) {
         // Send the packet.
         memset(&sin, 0, sizeof(struct sockaddr_in));
         sin.sin_family = AF_INET;
-        sin.sin_port = htons( (int)  RTPFile->GetLastPacketTrack()->Cookie1   );
+        sin.sin_port = htons( (int)(uintptr_t)  RTPFile->GetLastPacketTrack()->Cookie1   );
         sin.sin_addr.s_addr = inet_addr(IPAddress);
         sendto(s, Packet, PacketLength, 0, (struct sockaddr *)&sin, sizeof(struct sockaddr));
     }
