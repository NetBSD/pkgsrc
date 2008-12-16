$NetBSD: patch-ui-ctrlmenu.tcl,v 1.1.1.1 2008/12/16 19:35:46 sborrill Exp $

Add option to disable overlay UI

--- tcl/ui-ctrlmenu.tcl.orig	2008-12-14 12:21:43.000000000 +0000
+++ tcl/ui-ctrlmenu.tcl	2008-12-14 12:21:55.000000000 +0000
@@ -478,7 +478,8 @@
 	set transmitButton $w.send
 	global logoButton
 	set logoButton $w.logo
-
+	global overlayEnabled
+	set overlayEnabled [ yesno overlayEnabled ]
 	checkbutton $w.send -text "Transmit" \
 		-relief raised -command transmit \
 		-anchor w -variable transmitButtonState -font $f \
@@ -494,9 +495,12 @@
 		-relief raised -command logo_transmit \
 		-anchor w -variable logoButtonState -font $f \
 		-state normal -highlightthickness 0
-		
 #	pack $w.send $w.release $w.freeze -fill both
-	pack $w.send $w.logo $w.release -fill both
+	pack $w.send -fill both
+	if $overlayEnabled {
+		pack $w.logo  -fill both
+	}
+	pack $w.release -fill both
 }
 
 proc doNothing { args } {
@@ -1656,7 +1660,8 @@
 
 proc build.xmit w {
 	set f [smallfont]
-
+	global overlayEnabled
+	set overlayEnabled [ yesno overlayEnabled ]
 	label $w.label -text Transmission
 	frame $w.frame -relief sunken -borderwidth 2
 	pack $w.label -fill x
@@ -1672,8 +1677,9 @@
 	build.titlemaker $w.frame.combined.tm
 
 	pack $w.frame.combined.right -side top -expand 1 -fill x -padx 10 -anchor w
-	pack $w.frame.combined.tm -side bottom -expand 1 -fill y -pady 10 -anchor w
-	
+	if $overlayEnabled {
+		pack $w.frame.combined.tm -side bottom -expand 1 -fill y -pady 10 -anchor w
+	}
 	pack $w.frame.buttons -side left -padx 6 
 	pack $w.frame.combined -side right -expand 1 -fill x -padx 10 -anchor c
 
