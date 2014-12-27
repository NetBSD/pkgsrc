$NetBSD: patch-lib_mime.tcl,v 1.1 2014/12/27 00:20:06 dholland Exp $

Fix message date printing, from PR 49479; submitted upstream.

--- lib/mime.tcl        2013-09-16 11:48:55.000000000 +0700
+++ lib/mime.tcl        2014-12-16 08:59:57.000000000 +0700
@@ -1302,7 +1302,12 @@
     global mime

     catch {
-	set msgtime   [clock scan $time]
+	set msgtime   [regsub -all {\([^)]*\)} $time {}]
+	set msgtime   [string trim $msgtime]
+	if [regexp {.* -0000$} $msgtime] {
+	    return
+	}
+	set msgtime   [clock scan $msgtime -format "%a, %d %b %Y %T %Z"]
 	set localtime [clock format $msgtime -format " %T"]
 	if { [string first $localtime $time] == -1 } {
 	    Preferences_Resource mime(localTimeFormat) localTimeFormat \
