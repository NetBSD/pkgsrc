$NetBSD: patch-lib_fontsel.tcl,v 1.1 2025/05/25 15:04:07 vins Exp $

Make HTML font configurable.

--- lib/fontsel.tcl.orig	2017-11-10 04:42:24.000000000 +0000
+++ lib/fontsel.tcl
@@ -32,6 +32,7 @@ proc Font_Dialog {} {
 	    *Ftoc*Text.font
 	    *Msg*Text.font
 	    *Sedit*Text.font
+	    *HTML.font
 	} 
 	foreach resource $fontreslist {
 	    $m add command -label $resource -command "FontSetResource $resource \$font(current)"
