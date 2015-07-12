$NetBSD: patch-HTMLparser.c,v 1.1.2.2 2015/07/12 09:01:56 tron Exp $

Suggested patch for arbitrary-memory-access vulnerability, from
https://bugzilla.gnome.org/show_bug.cgi?id=746048

--- HTMLparser.c.orig	2014-10-06 10:48:11.000000000 +0000
+++ HTMLparser.c
@@ -3245,13 +3245,20 @@ htmlParseComment(htmlParserCtxtPtr ctxt)
 	ctxt->instate = state;
 	return;
     }
+    if ((ctxt->input->end - ctxt->input->cur) < 3) {
+        ctxt->instate = XML_PARSER_EOF;
+        htmlParseErr(ctxt, XML_ERR_COMMENT_NOT_FINISHED,
+                     "Comment not terminated\n", NULL, NULL);
+        xmlFree(buf);
+        return;
+    }
     q = CUR_CHAR(ql);
     NEXTL(ql);
     r = CUR_CHAR(rl);
     NEXTL(rl);
     cur = CUR_CHAR(l);
     len = 0;
-    while (IS_CHAR(cur) &&
+    while (((ctxt->input->end - ctxt->input->cur) > 0) && IS_CHAR(cur) &&
            ((cur != '>') ||
 	    (r != '-') || (q != '-'))) {
 	if (len + 5 >= size) {
@@ -3281,7 +3288,7 @@ htmlParseComment(htmlParserCtxtPtr ctxt)
 	}
     }
     buf[len] = 0;
-    if (!IS_CHAR(cur)) {
+    if (!(ctxt->input->end - ctxt->input->cur) || !IS_CHAR(cur)) {
 	htmlParseErr(ctxt, XML_ERR_COMMENT_NOT_FINISHED,
 	             "Comment not terminated \n<!--%.50s\n", buf, NULL);
 	xmlFree(buf);
@@ -4465,6 +4472,7 @@ htmlParseContentInternal(htmlParserCtxtP
     depth = ctxt->nameNr;
     while (1) {
 	long cons = ctxt->nbChars;
+    long rem = ctxt->input->end - ctxt->input->cur;
 
         GROW;
 
@@ -4540,7 +4548,7 @@ htmlParseContentInternal(htmlParserCtxtP
 	    /*
 	     * Sometimes DOCTYPE arrives in the middle of the document
 	     */
-	    if ((CUR == '<') && (NXT(1) == '!') &&
+	    if ((rem >= 9) && (CUR == '<') && (NXT(1) == '!') &&
 		(UPP(2) == 'D') && (UPP(3) == 'O') &&
 		(UPP(4) == 'C') && (UPP(5) == 'T') &&
 		(UPP(6) == 'Y') && (UPP(7) == 'P') &&
@@ -4554,7 +4562,7 @@ htmlParseContentInternal(htmlParserCtxtP
 	    /*
 	     * First case :  a comment
 	     */
-	    if ((CUR == '<') && (NXT(1) == '!') &&
+	    if ((rem >= 4) && (CUR == '<') && (NXT(1) == '!') &&
 		(NXT(2) == '-') && (NXT(3) == '-')) {
 		htmlParseComment(ctxt);
 	    }
@@ -4562,14 +4570,14 @@ htmlParseContentInternal(htmlParserCtxtP
 	    /*
 	     * Second case : a Processing Instruction.
 	     */
-	    else if ((CUR == '<') && (NXT(1) == '?')) {
+	    else if ((rem >= 2) && (CUR == '<') && (NXT(1) == '?')) {
 		htmlParsePI(ctxt);
 	    }
 
 	    /*
 	     * Third case :  a sub-element.
 	     */
-	    else if (CUR == '<') {
+	    else if ((rem >= 1) && (CUR == '<')) {
 		htmlParseElementInternal(ctxt);
 		if (currentNode != NULL) xmlFree(currentNode);
 
@@ -4581,7 +4589,7 @@ htmlParseContentInternal(htmlParserCtxtP
 	     * Fourth case : a reference. If if has not been resolved,
 	     *    parsing returns it's Name, create the node
 	     */
-	    else if (CUR == '&') {
+	    else if ((rem >= 1) && (CUR == '&')) {
 		htmlParseReference(ctxt);
 	    }
 
