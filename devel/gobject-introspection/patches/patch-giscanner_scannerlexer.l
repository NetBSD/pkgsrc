$NetBSD: patch-giscanner_scannerlexer.l,v 1.3 2013/10/04 15:36:30 jperkin Exp $

* Ignore __asm volatile as per PR pkg/46017
  https://bugzilla.gnome.org/show_bug.cgi?id=678794
* Support __inline__ for older OSX.

--- giscanner/scannerlexer.l.orig	2012-12-18 16:27:16.000000000 +0000
+++ giscanner/scannerlexer.l
@@ -134,6 +134,8 @@ stringtext				([^\\\"])|(\\.)
 ","					{ return ','; }
 "->"					{ return ARROW; }
 
+"__asm"[\t\f\v\r ]+"volatile"		{ if (!parse_ignored_macro()) REJECT; }
+"__asm__"[\t\f\v\r ]+"volatile"		{ if (!parse_ignored_macro()) REJECT; }
 "__asm" 	        	        { if (!parse_ignored_macro()) REJECT; }
 "__asm__" 	        	        { if (!parse_ignored_macro()) REJECT; }
 "__attribute__" 		        { if (!parse_ignored_macro()) REJECT; }
@@ -141,10 +143,13 @@ stringtext				([^\\\"])|(\\.)
 "__const"                               { return CONST; }
 "__extension__"                         { return EXTENSION; }
 "__inline"				{ return INLINE; }
+"__inline__"				{ return INLINE; }
 "__nonnull" 			        { if (!parse_ignored_macro()) REJECT; }
 "__signed__"				{ return SIGNED; }
 "__restrict"				{ return RESTRICT; }
 "__typeof"				{ if (!parse_ignored_macro()) REJECT; }
+"__volatile"				{ if (!parse_ignored_macro()) REJECT; }
+"__volatile__"				{ if (!parse_ignored_macro()) REJECT; }
 "_Bool"					{ return BOOL; }
 
 "G_GINT64_CONSTANT"			{ return INTL_CONST; }
