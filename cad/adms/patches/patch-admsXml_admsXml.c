$NetBSD: patch-admsXml_admsXml.c,v 1.1 2012/05/04 16:03:13 joerg Exp $

--- admsXml/admsXml.c.orig	2012-04-28 21:39:15.000000000 +0000
+++ admsXml/admsXml.c
@@ -254,6 +254,8 @@
 #include <admsObject/admsC.h>
 #include <time.h>
 
+#define inline static inline
+
 static int adms_donouse_xml_implicit_file=0;
 
 static p_admsttransform adms_admstpath_admsttransform(p_admsttransform myadmsttransform,const char*myname)
