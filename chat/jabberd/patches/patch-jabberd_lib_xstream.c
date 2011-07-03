$NetBSD: patch-jabberd_lib_xstream.c,v 1.1 2011/07/03 08:26:55 obache Exp $

* fix CVE-2011-1754

--- jabberd/lib/xstream.c.orig	2002-02-08 07:39:24.000000000 +0000
+++ jabberd/lib/xstream.c
@@ -142,6 +142,7 @@ xstream xstream_new(pool p, xstream_onNo
 
     /* create expat parser and ensure cleanup */
     newx->parser = XML_ParserCreate(NULL);
+    XML_SetDefaultHandler(newx->parser, NULL);
     XML_SetUserData(newx->parser, (void *)newx);
     XML_SetElementHandler(newx->parser, (void *)_xstream_startElement, (void *)_xstream_endElement);
     XML_SetCharacterDataHandler(newx->parser, (void *)_xstream_charData);
