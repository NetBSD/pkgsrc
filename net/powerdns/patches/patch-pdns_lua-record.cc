$NetBSD: patch-pdns_lua-record.cc,v 1.1 2020/07/02 13:01:38 otis Exp $

Rename some identifiers to non-clashing names.

Reference:
https://github.com/PowerDNS/pdns/issues/9279

--- pdns/lua-record.cc.orig	2020-02-25 06:57:13.000000000 +0000
+++ pdns/lua-record.cc
@@ -658,12 +658,12 @@ void setupLuaRecords()
         for(int i=0; i<8; ++i) {
           if(i)
             together+=":";
-          string quad;
+          string lquad;
           for(int j=0; j <4; ++j) {
-            quad.append(1, labels[31-i*4-j][0]);
+            lquad.append(1, labels[31-i*4-j][0]);
             together += labels[31-i*4-j][0];
           }
-          quads.push_back(quad);
+          quads.push_back(lquad);
         }
         ComboAddress ip6(together,0);
 
@@ -683,8 +683,8 @@ void setupLuaRecords()
           fmt % labels[i];
         fmt % dashed;
 
-        for(const auto& quad : quads)
-          fmt % quad;
+        for(const auto& lquad : quads)
+          fmt % lquad;
 
         return fmt.str();
       }
