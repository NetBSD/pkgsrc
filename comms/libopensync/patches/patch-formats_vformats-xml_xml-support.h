$NetBSD: patch-formats_vformats-xml_xml-support.h,v 1.1 2026/06/16 12:35:00 nia Exp $

Fix implicit declaration of malloc(3) in xmldoc.c, among others.

--- formats/vformats-xml/xml-support.h.orig	2026-06-16 12:23:15.638724338 +0000
+++ formats/vformats-xml/xml-support.h
@@ -9,6 +9,7 @@
 #include <opensync/opensync_xml.h>
 #include <string.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 #ifdef __cplusplus
 extern "C"
