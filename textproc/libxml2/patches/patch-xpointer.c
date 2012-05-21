$NetBSD: patch-xpointer.c,v 1.1.6.1 2012/05/21 15:13:36 tron Exp $

patches for these security problems:
	http://secunia.com/advisories/46632/
	http://secunia.com/advisories/49177/

--- xpointer.c.orig	2010-10-12 06:25:33.000000000 +0000
+++ xpointer.c
@@ -1007,21 +1007,14 @@ xmlXPtrEvalXPtrPart(xmlXPathParserContex
 		NEXT;
 		break;
 	    }
-	    *cur++ = CUR;
 	} else if (CUR == '(') {
 	    level++;
-	    *cur++ = CUR;
 	} else if (CUR == '^') {
-	    NEXT;
-	    if ((CUR == ')') || (CUR == '(') || (CUR == '^')) {
-		*cur++ = CUR;
-	    } else {
-		*cur++ = '^';
-		*cur++ = CUR;
+	    if ((NXT(1) == ')') || (NXT(1) == '(') || (NXT(1) == '^')) {
+		NEXT;
 	    }
-	} else {
-	    *cur++ = CUR;
 	}
+	*cur++ = CUR;
 	NEXT;
     }
     *cur = 0;
@@ -1269,6 +1262,7 @@ xmlXPtrEvalXPointer(xmlXPathParserContex
 	ctxt->valueNr = 0;
 	ctxt->valueMax = 10;
 	ctxt->value = NULL;
+	ctxt->valueFrame = 0;
     }
     SKIP_BLANKS;
     if (CUR == '/') {
