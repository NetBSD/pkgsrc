$NetBSD: patch-rec__control.cc,v 1.1 2020/06/17 22:55:11 otis Exp $

--- rec_control.cc.orig	2020-05-08 09:30:45.000000000 +0000
+++ rec_control.cc
@@ -39,7 +39,7 @@ static void initArguments(int argc, char
 {
   arg().set("config-dir","Location of configuration directory (recursor.conf)")=SYSCONFDIR;
 
-  arg().set("socket-dir",string("Where the controlsocket will live, ")+LOCALSTATEDIR+"/pdns-recursor when unset and not chrooted" )="";
+  arg().set("socket-dir",string("Where the controlsocket will live, ")+LOCALSTATEDIR+" when unset and not chrooted" )="";
   arg().set("chroot","switch to chroot jail")="";
   arg().set("process","When controlling multiple recursors, the target process number")="";
   arg().set("timeout", "Number of seconds to wait for the recursor to respond")="5";
@@ -72,7 +72,7 @@ static void initArguments(int argc, char
 
   if (::arg()["socket-dir"].empty()) {
     if (::arg()["chroot"].empty())
-      ::arg().set("socket-dir") = std::string(LOCALSTATEDIR) + "/pdns-recursor";
+      ::arg().set("socket-dir") = std::string(LOCALSTATEDIR);
     else
       ::arg().set("socket-dir") = ::arg()["chroot"] + "/";
   } else if (!::arg()["chroot"].empty()) {
