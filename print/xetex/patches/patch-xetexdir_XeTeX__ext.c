$NetBSD: patch-xetexdir_XeTeX__ext.c,v 1.1 2012/07/09 01:51:34 minskim Exp $

--- xetexdir/XeTeX_ext.c.orig	2011-02-25 11:49:36.000000000 +0000
+++ xetexdir/XeTeX_ext.c
@@ -182,7 +182,7 @@ const UInt32 byteMark				= 0x00000080UL;
 
 /* if the user specifies a paper size or output driver program */
 const char *papersize;
-const char *outputdriver = "xdvipdfmx -q -E"; /* default to portable xdvipdfmx driver */
+const char *outputdriver = "@XDVIPDFMX@ -q -E"; /* default to portable xdvipdfmx driver */
 
 
 void initversionstring(char **versions)
