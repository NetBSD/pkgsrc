$NetBSD: patch-nmap__dns.cc,v 1.1 2016/02/11 06:08:39 jklos Exp $

--- nmap_dns.cc.orig	2015-10-07 17:49:24.000000000 +0000
+++ nmap_dns.cc
@@ -1317,7 +1317,7 @@ bool DNS::Factory::ipToPtr(const sockadd
 
       std::string ipv4 = ipv4_c;
       std::string octet;
-      for (std::string::const_reverse_iterator c=ipv4.rbegin(); c != ipv4.rend(); ++c)
+      for (std::reverse_iterator<std::string::iterator> c=ipv4.rbegin(); c != ipv4.rend(); ++c)
         if((*c)=='.')
         {
           ptr += octet + ".";
@@ -1382,7 +1382,7 @@ bool DNS::Factory::ptrToIp(const std::st
   {
 
     std::string octet;
-    for (std::string::const_reverse_iterator it = mptr.rend()-pos; it != mptr.rend(); ++it)
+    for (std::reverse_iterator<std::string::iterator> it = mptr.rend()-pos; it != mptr.rend(); ++it)
     {
       const char &c = *it;
       if(c == '.')
