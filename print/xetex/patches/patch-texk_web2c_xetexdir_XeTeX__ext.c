$NetBSD: patch-texk_web2c_xetexdir_XeTeX__ext.c,v 1.1 2012/07/31 18:44:03 wiz Exp $

Prepare for patching in absolute pkgsrc path to xdvipdfmx binary.

--- texk/web2c/xetexdir/XeTeX_ext.c.orig	2012-03-19 08:34:01.000000000 +0000
+++ texk/web2c/xetexdir/XeTeX_ext.c
@@ -173,7 +173,7 @@ const UInt32 byteMark				= 0x00000080UL;
 
 /* if the user specifies a paper size or output driver program */
 const char *papersize;
-const char *outputdriver = "xdvipdfmx -q -E"; /* default to portable xdvipdfmx driver */
+const char *outputdriver = "@XDVIPDFMX@ -q -E"; /* default to portable xdvipdfmx driver */
 
 
 void initversionstring(char **versions)
