$NetBSD: patch-services.gawk,v 1.3 2022/11/28 02:15:03 jschauma Exp $

o Service numbers are authoritatively sourced from IANA
o New services file has <port> <protocol> instead of <port>/<protocol>

--- services.gawk.orig	2008-03-05 12:51:45.000000000 -0500
+++ services.gawk	2022-11-27 21:03:42.805245025 -0500
@@ -11,7 +11,7 @@
     } else {
 	strip = 0
 	print "# See also: services(5)" \
-	    ", http://www.sethwklein.net/projects/iana-etc/\n#"
+	    ", https://www.iana.org/assignments/service-names-port-numbers/\n#"
     }
     while (getline <"port-aliases") {
 	sub(/#.*/, "")
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
