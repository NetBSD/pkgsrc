$NetBSD: patch-admsXml_admsXml.c,v 1.3 2012/06/29 12:31:13 joerg Exp $

--- admsXml/admsXml.c.orig	2012-06-28 14:59:22.000000000 +0000
+++ admsXml/admsXml.c
@@ -304,7 +304,7 @@ static p_admstvariable adms_admstpath_ad
 typedef void (t_admsttransform_evaluate) (p_admsttransform myadmsttransform,p_admst myadmstparent);
 typedef void (*p_admsttransform_evaluate) (p_admsttransform myadmsttransform,p_admst myadmstparent);
 #define _t_admsttransform_evaluate(function) void (function) (p_admsttransform myadmsttransform,p_admst myadmstparent)
-#define _t_inline_admsttransform_evaluate(function) inline  _t_admsttransform_evaluate(function)
+#define _t_inline_admsttransform_evaluate(function) static  _t_admsttransform_evaluate(function)
 
 /*xml parser built from admstpath.xml*/
 static char *adms_admsttext_tostring (const p_admst myadmstparent,const p_admsttext myadmsttext);
