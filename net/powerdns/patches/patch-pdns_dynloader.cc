$NetBSD: patch-pdns_dynloader.cc,v 1.2 2014/12/10 14:50:09 fhajny Exp $

Resolve boost symbol ambiguity.
--- pdns/dynloader.cc.orig	2014-04-29 11:02:00.000000000 +0000
+++ pdns/dynloader.cc
@@ -103,9 +103,9 @@ int main(int argc, char **argv)
 
   try {
     string command=commands[0];
-    shared_ptr<DynMessenger> D;
+    boost::shared_ptr<DynMessenger> D;
     if(::arg()["remote-address"].empty())
-      D=shared_ptr<DynMessenger>(new DynMessenger(localdir,socketname));
+      D=boost::shared_ptr<DynMessenger>(new DynMessenger(localdir,socketname));
     else {
       uint16_t port;
       try {
@@ -116,7 +116,7 @@ int main(int argc, char **argv)
         exit(99);
       }
       
-      D=shared_ptr<DynMessenger>(new DynMessenger(ComboAddress(::arg()["remote-address"], port), ::arg()["secret"]));
+      D=boost::shared_ptr<DynMessenger>(new DynMessenger(ComboAddress(::arg()["remote-address"], port), ::arg()["secret"]));
     }
 
     string message;
