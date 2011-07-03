$NetBSD: patch-jabberd_mio__xml.c,v 1.1 2011/07/03 08:26:55 obache Exp $

* fix CVE-2011-1754

--- jabberd/mio_xml.c.orig	2002-02-08 07:39:27.000000000 +0000
+++ jabberd/mio_xml.c
@@ -118,6 +118,7 @@ void _mio_xstream_init(mio m)
 	    /* Initialize the parser */
 	    m->parser = XML_ParserCreate(NULL);
 	    XML_SetUserData(m->parser, m);
+	    XML_SetDefaultHandler(m->parser, NULL);
 	    XML_SetElementHandler(m->parser, (void*)_mio_xstream_startElement, (void*)_mio_xstream_endElement);
 	    XML_SetCharacterDataHandler(m->parser, (void*)_mio_xstream_CDATA);
 	    /* Setup a cleanup routine to release the parser when everything is done */
