$NetBSD: patch-tkined_apps_ip__discover.tcl,v 1.1 2014/03/05 13:52:29 he Exp $

Ensure we unset the global variable...

--- tkined/apps/ip_discover.tcl.orig	Fri Jun 12 09:23:35 1998
+++ tkined/apps/ip_discover.tcl	Wed Sep  6 22:56:34 2000
@@ -56,7 +56,10 @@
     foreach name {
 	nodes networks links ids trace mask fip name address gateways
     } {
-	catch {unset $name}
+	catch {
+	    global $name
+	    unset $name
+	}
     }
 }
 
