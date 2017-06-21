$NetBSD: patch-valid.c,v 1.2 2017/06/21 00:23:24 tez Exp $

Upstream commit by Daniel Veillard

Fix NULL pointer deref in xmlDumpElementContent
Can only be triggered in recovery mode.
Fixes bug 758422 (CVE-2017-5969).


xmlSnprintfElementContent failed to correctly check the available
buffer space in two locations.
Fixes bug 781333 (CVE-2017-9047) and bug 781701 (CVE-2017-9048).
From: https://git.gnome.org/browse/libxml2/commit/?id=932cc9896ab41475d4aa429c27d9afd175959d74


--- valid.c.orig	2017-06-21 00:07:08.204619100 +0000
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
@@ -1262,22 +1266,23 @@ xmlSnprintfElementContent(char *buf, int
         case XML_ELEMENT_CONTENT_PCDATA:
             strcat(buf, "#PCDATA");
 	    break;
-	case XML_ELEMENT_CONTENT_ELEMENT:
+	case XML_ELEMENT_CONTENT_ELEMENT: {
+            int qnameLen = xmlStrlen(content->name);
+
+	    if (content->prefix != NULL)
+                qnameLen += xmlStrlen(content->prefix) + 1;
+	    if (size - len < qnameLen + 10) {
+		strcat(buf, " ...");
+		return;
+	    }
 	    if (content->prefix != NULL) {
-		if (size - len < xmlStrlen(content->prefix) + 10) {
-		    strcat(buf, " ...");
-		    return;
-		}
 		strcat(buf, (char *) content->prefix);
 		strcat(buf, ":");
 	    }
-	    if (size - len < xmlStrlen(content->name) + 10) {
-		strcat(buf, " ...");
-		return;
-	    }
 	    if (content->name != NULL)
 		strcat(buf, (char *) content->name);
 	    break;
+        }
 	case XML_ELEMENT_CONTENT_SEQ:
 	    if ((content->c1->type == XML_ELEMENT_CONTENT_OR) ||
 	        (content->c1->type == XML_ELEMENT_CONTENT_SEQ))
@@ -1319,6 +1324,7 @@ xmlSnprintfElementContent(char *buf, int
 		xmlSnprintfElementContent(buf, size, content->c2, 0);
 	    break;
     }
+    if (size - strlen(buf) <= 2) return;
     if (englob)
         strcat(buf, ")");
     switch (content->ocur) {
