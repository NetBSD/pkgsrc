$NetBSD: patch-pdns_dynloader.cc,v 1.3 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- pdns/dynloader.cc.orig	2015-03-02 13:17:11.000000000 +0000
+++ pdns/dynloader.cc
@@ -97,9 +97,9 @@ int main(int argc, char **argv)
   
   try {
     string command=commands[0];
-    shared_ptr<DynMessenger> D;
+    boost::shared_ptr<DynMessenger> D;
     if(::arg()["remote-address"].empty())
-      D=shared_ptr<DynMessenger>(new DynMessenger(socketname));
+      D=boost::shared_ptr<DynMessenger>(new DynMessenger(socketname));
     else {
       uint16_t port;
       try {
@@ -110,7 +110,7 @@ int main(int argc, char **argv)
         exit(99);
       }
       
-      D=shared_ptr<DynMessenger>(new DynMessenger(ComboAddress(::arg()["remote-address"], port), ::arg()["secret"]));
+      D=boost::shared_ptr<DynMessenger>(new DynMessenger(ComboAddress(::arg()["remote-address"], port), ::arg()["secret"]));
     }
 
     string message;
