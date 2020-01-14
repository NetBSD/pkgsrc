$NetBSD: patch-proto__xboard.cc,v 1.1 2020/01/14 08:48:44 hauke Exp $

We install the GNU chess binary as 'gnuchess'

--- proto_xboard.cc.orig	2008-02-22 15:51:22.000000000 +0000
+++ proto_xboard.cc
@@ -1304,7 +1304,7 @@ void GnuChess4Protocol::initEngine() {
 
 void GnuChess4Protocol::readDialog() {
   XBoardProtocol::readDialog();
-  strcpy(EngineCommandLine,"gnuchessx");
+  strcpy(EngineCommandLine,"gnuchess");
   EngineRunDir[0]=0;
 
   if (ebm) {
