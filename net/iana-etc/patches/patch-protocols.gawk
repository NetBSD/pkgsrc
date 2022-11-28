$NetBSD: patch-protocols.gawk,v 1.3 2022/11/28 17:44:41 jschauma Exp $

o Munge TTP/IPTM into aliases.
o If an alias is identical to the name, upper case it (PR 44311).
o Protocol numbers are authoritatively sourced from IANA

--- protocols.gawk.orig	2006-11-14 13:20:26.000000000 -0500
+++ protocols.gawk	2022-11-28 12:33:08.350923778 -0500
@@ -14,7 +14,7 @@
     } else {
 	strip = 0
 	print "# See also: protocols(5)" \
-	    ", http://www.sethwklein.net/projects/iana-etc/\n#"
+	    ", https://www.iana.org/assignments/protocol-numbers/\n#"
 	format = "%-12s %3s %-12s # %s\n"
 	header_printed = 0
     }
@@ -26,7 +26,19 @@
 	header_printed = 1;
     }
     sub(/^[ \t]*/, "", f[3])
-    printf format, tolower(f[2]), f[1], f[2], f[3]
+    alias=f[2]
+    if (tolower(f[2]) == f[2]) {
+        alias = toupper(f[2])
+    }
+    # IANA assigned '84' to both TTP and IPTM; for
+    # /etc/protocols, we munge these into aliases:
+    if (tolower(f[2]) == "ttp") {
+        alias = "TTP iptm IPTM"
+    }
+    if (tolower(f[2]) == "iptm") {
+        f[2] = "#iptm"
+    }
+    printf format, tolower(f[2]), f[1], alias, f[3]
     next
 }
 !strip { print "# " $0 }
