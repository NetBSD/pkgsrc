$NetBSD: patch-valid.c,v 1.2.2.2 2017/06/21 18:17:36 bsiegert Exp $

Upstream commit by Daniel Veillard

Fix NULL pointer deref in xmlDumpElementContent
Can only be triggered in recovery mode.
Fixes bug 758422 (CVE-2017-5969).


--- valid.c.orig	2016-05-23 07:25:25.000000000 +0000
+++ valid.c
@@ -1172,29 +1172,33 @@ xmlDumpElementContent(xmlBufferPtr buf, 
 	    xmlBufferWriteCHAR(buf, content->name);
 	    break;
 	case XML_ELEMENT_CONTENT_SEQ:
-	    if ((content->c1->type == XML_ELEMENT_CONTENT_OR) ||
-	        (content->c1->type == XML_ELEMENT_CONTENT_SEQ))
+	    if ((content->c1 != NULL) &&
+	        ((content->c1->type == XML_ELEMENT_CONTENT_OR) ||
+	         (content->c1->type == XML_ELEMENT_CONTENT_SEQ)))
 		xmlDumpElementContent(buf, content->c1, 1);
 	    else
 		xmlDumpElementContent(buf, content->c1, 0);
             xmlBufferWriteChar(buf, " , ");
-	    if ((content->c2->type == XML_ELEMENT_CONTENT_OR) ||
-	        ((content->c2->type == XML_ELEMENT_CONTENT_SEQ) &&
-		 (content->c2->ocur != XML_ELEMENT_CONTENT_ONCE)))
+	    if ((content->c2 != NULL) &&
+	        ((content->c2->type == XML_ELEMENT_CONTENT_OR) ||
+	         ((content->c2->type == XML_ELEMENT_CONTENT_SEQ) &&
+		  (content->c2->ocur != XML_ELEMENT_CONTENT_ONCE))))
 		xmlDumpElementContent(buf, content->c2, 1);
 	    else
 		xmlDumpElementContent(buf, content->c2, 0);
 	    break;
 	case XML_ELEMENT_CONTENT_OR:
-	    if ((content->c1->type == XML_ELEMENT_CONTENT_OR) ||
-	        (content->c1->type == XML_ELEMENT_CONTENT_SEQ))
+	    if ((content->c1 != NULL) &&
+	        ((content->c1->type == XML_ELEMENT_CONTENT_OR) ||
+	         (content->c1->type == XML_ELEMENT_CONTENT_SEQ)))
 		xmlDumpElementContent(buf, content->c1, 1);
 	    else
 		xmlDumpElementContent(buf, content->c1, 0);
             xmlBufferWriteChar(buf, " | ");
-	    if ((content->c2->type == XML_ELEMENT_CONTENT_SEQ) ||
-	        ((content->c2->type == XML_ELEMENT_CONTENT_OR) &&
-		 (content->c2->ocur != XML_ELEMENT_CONTENT_ONCE)))
+	    if ((content->c2 != NULL) &&
+	        ((content->c2->type == XML_ELEMENT_CONTENT_SEQ) ||
+	         ((content->c2->type == XML_ELEMENT_CONTENT_OR) &&
+		  (content->c2->ocur != XML_ELEMENT_CONTENT_ONCE))))
 		xmlDumpElementContent(buf, content->c2, 1);
 	    else
 		xmlDumpElementContent(buf, content->c2, 0);
