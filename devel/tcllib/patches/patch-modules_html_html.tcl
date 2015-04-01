$NetBSD: patch-modules_html_html.tcl,v 1.1.2.2 2015/04/01 03:31:54 hiramatsu Exp $

html - Fixed XSS vulnerability of "textarea" command. Now properly quoting the input value.
http://core.tcl.tk/tcllib/info/09110adc43

--- modules/html/html.tcl.orig	2015-03-21 17:08:44.000000000 +0000
+++ modules/html/html.tcl
@@ -912,7 +912,7 @@ proc ::html::selectPlain {name param cho
 #	The html fragment
 
 proc ::html::textarea {name {param {}} {current {}}} {
-    ::set value [ncgi::value $name $current]
+    ::set value [quoteFormValue [ncgi::value $name $current]]
     return "<[string trimright \
 	"textarea name=\"$name\"\
 		[tagParam textarea $param]"]>$value</textarea>\n"
