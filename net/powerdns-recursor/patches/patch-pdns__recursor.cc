$NetBSD: patch-pdns__recursor.cc,v 1.6 2020/06/17 22:55:11 otis Exp $

--- pdns_recursor.cc.orig	2020-05-08 09:31:59.000000000 +0000
+++ pdns_recursor.cc
@@ -4673,7 +4673,7 @@ int main(int argc, char **argv)
     ::arg().set("socket-group","Group of socket")="";
     ::arg().set("socket-mode", "Permissions for socket")="";
 
-    ::arg().set("socket-dir",string("Where the controlsocket will live, ")+LOCALSTATEDIR+"/pdns-recursor when unset and not chrooted" )="";
+    ::arg().set("socket-dir",string("Where the controlsocket will live, ")+LOCALSTATEDIR+" when unset and not chrooted" )="";
     ::arg().set("delegation-only","Which domains we only accept delegations from")="";
     ::arg().set("query-local-address","Source IP address for sending queries")="0.0.0.0";
     ::arg().set("query-local-address6","Source IPv6 address for sending queries. IF UNSET, IPv6 WILL NOT BE USED FOR OUTGOING QUERIES")="";
@@ -4848,7 +4848,7 @@ int main(int argc, char **argv)
 
     if (::arg()["socket-dir"].empty()) {
       if (::arg()["chroot"].empty())
-        ::arg().set("socket-dir") = std::string(LOCALSTATEDIR) + "/pdns-recursor";
+        ::arg().set("socket-dir") = std::string(LOCALSTATEDIR);
       else
         ::arg().set("socket-dir") = "/";
     }
