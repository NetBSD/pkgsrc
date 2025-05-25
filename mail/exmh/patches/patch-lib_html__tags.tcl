$NetBSD: patch-lib_html__tags.tcl,v 1.1 2025/05/25 15:04:07 vins Exp $

Workaround for unconfigurable font family and inconsistent sizing. 

--- lib/html_tags.tcl.orig	2017-11-10 04:42:24.000000000 +0000
+++ lib/html_tags.tcl
@@ -51,19 +51,8 @@ proc HMtag_base {win param text} {
 # are likely
 
 proc HMset_font {win tag font} {
-	global Fonts
-	set label [StatusLabel $win]	;# This may not exist for msg dialogs
-	if {![info exists Fonts($font)]} {
-		set Fonts($font) 1
-		catch {$label configure -fg blue}
-		Status $win "downloading font $font"
-		set status 1
-	}
-	catch {$win tag configure $tag -font $font}
-	if [info exists status] {
-	    StatusLazy $win {}
-	    catch {$label configure -fg black}
-	}
+    set font [option get . HTML.font {}]
+    catch {$win tag configure $tag -font {$font 10}}
 }
 
 # Lets invent a new HTML tag, just for fun.
