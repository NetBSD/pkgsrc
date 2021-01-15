$NetBSD: patch-src_greeting.cc,v 1.1 2021/01/15 22:01:29 schmonz Exp $

Fix "error: invalid suffix on literal; C++11 requires a space between
literal and identifier" on at least FreeBSD.

--- src/greeting.cc.orig	2005-03-22 09:47:34.000000000 +0000
+++ src/greeting.cc
@@ -69,7 +69,7 @@ void Binc::showGreeting(void)
   string tmp = session.globalconfig["Security"]["version in greeting"];
   lowercase(tmp);
   if (tmp == "yes")
-    version = "v"VERSION" ";
+    version = "v" VERSION" ";
 
   com << "* OK Welcome to Binc IMAP " << version 
       << "Copyright (C) 2002-2005 Andreas Aardal Hanssen at "
