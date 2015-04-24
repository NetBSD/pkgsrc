$NetBSD: patch-xmlreader.c,v 1.1 2015/04/24 11:32:29 spz Exp $

patch for CVE-2015-1819 Enforce the reader to run in constant memory
from https://git.gnome.org/browse/libxml2/commit/?id=213f1fe0d76d30eaed6e5853057defc43e6df2c9
part 3

--- xmlreader.c.orig	2014-10-06 12:05:09.000000000 +0000
+++ xmlreader.c
@@ -2091,6 +2091,9 @@ xmlNewTextReader(xmlParserInputBufferPtr
 		"xmlNewTextReader : malloc failed\n");
 	return(NULL);
     }
+    /* no operation on a reader should require a huge buffer */
+    xmlBufSetAllocationScheme(ret->buffer,
+			      XML_BUFFER_ALLOC_BOUNDED);
     ret->sax = (xmlSAXHandler *) xmlMalloc(sizeof(xmlSAXHandler));
     if (ret->sax == NULL) {
 	xmlBufFree(ret->buffer);
@@ -3616,6 +3619,7 @@ xmlTextReaderConstValue(xmlTextReaderPtr
 	    return(((xmlNsPtr) node)->href);
         case XML_ATTRIBUTE_NODE:{
 	    xmlAttrPtr attr = (xmlAttrPtr) node;
+            const xmlChar *ret;
 
 	    if ((attr->children != NULL) &&
 	        (attr->children->type == XML_TEXT_NODE) &&
@@ -3629,10 +3633,21 @@ xmlTextReaderConstValue(xmlTextReaderPtr
                                         "xmlTextReaderSetup : malloc failed\n");
                         return (NULL);
                     }
+		    xmlBufSetAllocationScheme(reader->buffer,
+		                              XML_BUFFER_ALLOC_BOUNDED);
                 } else
                     xmlBufEmpty(reader->buffer);
 	        xmlBufGetNodeContent(reader->buffer, node);
-		return(xmlBufContent(reader->buffer));
+		ret = xmlBufContent(reader->buffer);
+		if (ret == NULL) {
+		    /* error on the buffer best to reallocate */
+		    xmlBufFree(reader->buffer);
+		    reader->buffer = xmlBufCreateSize(100);
+		    xmlBufSetAllocationScheme(reader->buffer,
+		                              XML_BUFFER_ALLOC_BOUNDED);
+		    ret = BAD_CAST "";
+		}
+		return(ret);
 	    }
 	    break;
 	}
@@ -5131,6 +5146,9 @@ xmlTextReaderSetup(xmlTextReaderPtr read
                         "xmlTextReaderSetup : malloc failed\n");
         return (-1);
     }
+    /* no operation on a reader should require a huge buffer */
+    xmlBufSetAllocationScheme(reader->buffer,
+			      XML_BUFFER_ALLOC_BOUNDED);
     if (reader->sax == NULL)
 	reader->sax = (xmlSAXHandler *) xmlMalloc(sizeof(xmlSAXHandler));
     if (reader->sax == NULL) {
