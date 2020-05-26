$NetBSD: patch-src_irc_server.cpp,v 1.1 2020/05/26 11:27:01 joerg Exp $

--- src/irc/server.cpp.orig	2020-05-25 23:52:06.113560096 +0000
+++ src/irc/server.cpp
@@ -3709,7 +3709,7 @@ bool Server::isAChannel(const QString &c
 {
     if (channel.isEmpty()) return false;
 
-    return (getChannelTypes().contains(channel.at(0)) > 0);
+    return (getChannelTypes().contains(channel.at(0)));
 }
 
 void Server::addRawLog(bool show)
