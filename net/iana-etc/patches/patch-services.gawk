$NetBSD: patch-services.gawk,v 1.2 2012/08/25 13:01:42 christos Exp $

o New services file has <port> <protocol> instead of <port>/<protocol>

--- services.gawk	2008-03-05 19:51:45.000000000 +0200
+++ services.gawk	2012-08-25 13:36:06.000000000 +0300
@@ -22,15 +22,15 @@
     }
 }
 { sub(/\r/, "") }
-#           1:name               2:ws    3:port  4:range     5:proto  6:comment
-match($0, /(^[[:alnum:]][^ \t]+)([ \t]+)([0-9]+)(-[0-9]+)?\/([^ \t]+)(.*)/, f) \
+#           1:name               2:ws    3:port  4:range     6:proto  7:comment
+match($0, /(^[[:alnum:]][^ \t]+)([ \t]+)([0-9]+)(-[0-9]+)?([ \t]+)(dccp|sctp|tcp|udp)(.*)/, f) \
 && f[3] != "0" {
 # port 0 means unallocated, per port-numbers
     name = f[1]
     whitespace = f[2]
     port = f[3]
-    protocol = f[5]
-    comment = f[6]
+    protocol = f[6]
+    comment = f[7]
     if (strip) {
 	whitespace = "\t"
 	comment = ""
