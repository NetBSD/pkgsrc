$NetBSD: patch-src_irc_irccharsets.cpp,v 1.1 2020/05/26 11:27:01 joerg Exp $

--- src/irc/irccharsets.cpp.orig	2020-05-25 23:57:59.317709054 +0000
+++ src/irc/irccharsets.cpp
@@ -90,7 +90,7 @@ namespace Konversation
 
     bool IRCCharsets::isValidEncoding( const QString& shortName )
     {
-        return ( m_shortNames.contains( shortName ) > 0 );
+        return ( m_shortNames.contains( shortName ) );
     }
 
     QString IRCCharsets::encodingForLocale()
