$NetBSD: patch-ui-resource.tcl,v 1.1.1.1 2008/12/16 19:35:46 sborrill Exp $

Add option to disable overlay UI

--- tcl/ui-resource.tcl.orig	2008-12-14 12:21:50.000000000 +0000
+++ tcl/ui-resource.tcl	2008-12-14 12:21:55.000000000 +0000
@@ -237,6 +237,7 @@
 	option add Vic.overlayFilename "" startupFile
 	option add Vic.overlayX "0" startupFile
 	option add Vic.overlayY "0" startupFile
+	option add Vic.overlayEnabled true startupFile
 
 	# Init fonts
         if {![string match [ windowingsystem] "aqua"]} {
