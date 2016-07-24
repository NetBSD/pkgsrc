$NetBSD: patch-libgdome_gdomecore_gdome-xml-documentt.c,v 1.2 2016/07/24 21:02:45 rillig Exp $

Fix build with new libxml2 API.

--- libgdome/gdomecore/gdome-xml-documentt.c.orig	2012-11-19 01:08:40.000000000 +0000
+++ libgdome/gdomecore/gdome-xml-documentt.c
@@ -342,7 +342,7 @@ gdome_xml_dt_internalSubset (GdomeDocume
 	}
 	xmlNodeDumpOutput (out_buff, NULL, (xmlNode *)is, 0, 0, NULL);
 	xmlOutputBufferFlush(out_buff);
-	ret = g_strndup (out_buff->buffer->content, out_buff->buffer->use);
+	ret = g_strndup (xmlBufferContent(out_buff->buffer), xmlBufferLength(out_buff->buffer));
 	(void)xmlOutputBufferClose(out_buff);
 
 	return gdome_xml_str_mkref_own (ret);
