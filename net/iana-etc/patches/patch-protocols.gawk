$NetBSD: patch-protocols.gawk,v 1.1 2022/11/28 02:15:03 jschauma Exp $

o Protocol numbers are authoritatively sourced from IANA

--- protocols.gawk.orig	2022-11-27 21:04:38.855183965 -0500
+++ protocols.gawk	2022-11-27 21:05:09.916463115 -0500
@@ -14,7 +14,7 @@
     } else {
 	strip = 0
 	print "# See also: protocols(5)" \
-	    ", http://www.sethwklein.net/projects/iana-etc/\n#"
+	    ", https://www.iana.org/assignments/protocol-numbers/\n#"
 	format = "%-12s %3s %-12s # %s\n"
 	header_printed = 0
     }
