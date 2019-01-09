$NetBSD: patch-xmlcatalog.c,v 1.1 2019/01/09 19:09:03 adam Exp $

Parametrize SGML catalog directory.

--- xmlcatalog.c.orig	2014-10-03 11:28:06.000000000 +0000
+++ xmlcatalog.c
@@ -43,7 +43,7 @@ static char *filename = NULL;
 
 
 #ifndef XML_SGML_DEFAULT_CATALOG
-#define XML_SGML_DEFAULT_CATALOG "/etc/sgml/catalog"
+#define XML_SGML_DEFAULT_CATALOG "@@SGML_DEFAULT_CATALOG@@"
 #endif
 
 /************************************************************************
