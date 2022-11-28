$NetBSD: patch-protocols.gawk,v 1.2 2022/11/28 17:05:08 jschauma Exp $

o If an alias is identical to the name, upper case it (PR 44311).
o Protocol numbers are authoritatively sourced from IANA

--- protocols.gawk	2022-11-28 11:49:15.381735930 -0500
+++ protocols.gawk.orig	2006-11-14 13:20:26.000000000 -0500
@@ -14,7 +14,7 @@
     } else {
 	strip = 0
 	print "# See also: protocols(5)" \
-	    ", http://www.sethwklein.net/projects/iana-etc/\n#"
+	    ", https://www.iana.org/assignments/protocol-numbers/\n#"
 	format = "%-12s %3s %-12s # %s\n"
 	header_printed = 0
     }
@@ -26,6 +26,9 @@
 	header_printed = 1;
     }
     sub(/^[ \t]*/, "", f[3])
+    if (tolower(f[2]) == f[2]) {
+        f[2] = toupper(f[2])
+    }
     printf format, tolower(f[2]), f[1], f[2], f[3]
     next
 }
