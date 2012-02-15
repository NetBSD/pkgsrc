$NetBSD: patch-giscanner_scannerlexer.l,v 1.1 2012/02/15 16:42:36 martin Exp $

--- giscanner/scannerlexer.l.orig	2011-06-10 17:36:50.000000000 +0200
+++ giscanner/scannerlexer.l	2012-02-15 16:10:33.000000000 +0100
@@ -134,6 +134,8 @@
 ","					{ return ','; }
 "->"					{ return ARROW; }
 
+"__asm"[\t\f\v\r ]+"volatile"		{ if (!parse_ignored_macro()) REJECT; }
+"__asm__"[\t\f\v\r ]+"volatile"		{ if (!parse_ignored_macro()) REJECT; }
 "__asm" 	        	        { if (!parse_ignored_macro()) REJECT; }
 "__asm__" 	        	        { if (!parse_ignored_macro()) REJECT; }
 "__attribute__" 		        { if (!parse_ignored_macro()) REJECT; }
