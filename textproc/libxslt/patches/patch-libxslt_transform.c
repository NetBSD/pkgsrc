$NetBSD: patch-libxslt_transform.c,v 1.1 2022/09/13 21:34:00 gutteridge Exp $

Address CVE-2021-30560
https://gitlab.gnome.org/GNOME/libxslt/-/commit/50f9c9cd3b7dfe9b3c8c795247752d1fdcadcac8

--- libxslt/transform.c.orig	2019-10-23 17:36:39.000000000 +0000
+++ libxslt/transform.c
@@ -1895,7 +1895,7 @@ static void
 xsltDefaultProcessOneNode(xsltTransformContextPtr ctxt, xmlNodePtr node,
 			  xsltStackElemPtr params) {
     xmlNodePtr copy;
-    xmlNodePtr delete = NULL, cur;
+    xmlNodePtr cur;
     int nbchild = 0, oldSize;
     int childno = 0, oldPos;
     xsltTemplatePtr template;
@@ -1968,54 +1968,13 @@ xsltDefaultProcessOneNode(xsltTransformC
 	    return;
     }
     /*
-     * Handling of Elements: first pass, cleanup and counting
+     * Handling of Elements: first pass, counting
      */
     cur = node->children;
     while (cur != NULL) {
-	switch (cur->type) {
-	    case XML_TEXT_NODE:
-	    case XML_CDATA_SECTION_NODE:
-	    case XML_DOCUMENT_NODE:
-	    case XML_HTML_DOCUMENT_NODE:
-	    case XML_ELEMENT_NODE:
-	    case XML_PI_NODE:
-	    case XML_COMMENT_NODE:
-		nbchild++;
-		break;
-            case XML_DTD_NODE:
-		/* Unlink the DTD, it's still reachable using doc->intSubset */
-		if (cur->next != NULL)
-		    cur->next->prev = cur->prev;
-		if (cur->prev != NULL)
-		    cur->prev->next = cur->next;
-		break;
-	    default:
-#ifdef WITH_XSLT_DEBUG_PROCESS
-		XSLT_TRACE(ctxt,XSLT_TRACE_PROCESS_NODE,xsltGenericDebug(xsltGenericDebugContext,
-		 "xsltDefaultProcessOneNode: skipping node type %d\n",
-		                 cur->type));
-#endif
-		delete = cur;
-	}
+	if (IS_XSLT_REAL_NODE(cur))
+	    nbchild++;
 	cur = cur->next;
-	if (delete != NULL) {
-#ifdef WITH_XSLT_DEBUG_PROCESS
-	    XSLT_TRACE(ctxt,XSLT_TRACE_PROCESS_NODE,xsltGenericDebug(xsltGenericDebugContext,
-		 "xsltDefaultProcessOneNode: removing ignorable blank node\n"));
-#endif
-	    xmlUnlinkNode(delete);
-	    xmlFreeNode(delete);
-	    delete = NULL;
-	}
-    }
-    if (delete != NULL) {
-#ifdef WITH_XSLT_DEBUG_PROCESS
-	XSLT_TRACE(ctxt,XSLT_TRACE_PROCESS_NODE,xsltGenericDebug(xsltGenericDebugContext,
-	     "xsltDefaultProcessOneNode: removing ignorable blank node\n"));
-#endif
-	xmlUnlinkNode(delete);
-	xmlFreeNode(delete);
-	delete = NULL;
     }
 
     /*
@@ -4864,7 +4823,7 @@ xsltApplyTemplates(xsltTransformContextP
     xsltStylePreCompPtr comp = (xsltStylePreCompPtr) castedComp;
 #endif
     int i;
-    xmlNodePtr cur, delNode = NULL, oldContextNode;
+    xmlNodePtr cur, oldContextNode;
     xmlNodeSetPtr list = NULL, oldList;
     xsltStackElemPtr withParams = NULL;
     int oldXPProximityPosition, oldXPContextSize;
@@ -4998,73 +4957,9 @@ xsltApplyTemplates(xsltTransformContextP
 	else
 	    cur = NULL;
 	while (cur != NULL) {
-	    switch (cur->type) {
-		case XML_TEXT_NODE:
-		    if ((IS_BLANK_NODE(cur)) &&
-			(cur->parent != NULL) &&
-			(cur->parent->type == XML_ELEMENT_NODE) &&
-			(ctxt->style->stripSpaces != NULL)) {
-			const xmlChar *val;
-
-			if (cur->parent->ns != NULL) {
-			    val = (const xmlChar *)
-				  xmlHashLookup2(ctxt->style->stripSpaces,
-						 cur->parent->name,
-						 cur->parent->ns->href);
-			    if (val == NULL) {
-				val = (const xmlChar *)
-				  xmlHashLookup2(ctxt->style->stripSpaces,
-						 BAD_CAST "*",
-						 cur->parent->ns->href);
-			    }
-			} else {
-			    val = (const xmlChar *)
-				  xmlHashLookup2(ctxt->style->stripSpaces,
-						 cur->parent->name, NULL);
-			}
-			if ((val != NULL) &&
-			    (xmlStrEqual(val, (xmlChar *) "strip"))) {
-			    delNode = cur;
-			    break;
-			}
-		    }
-		    /* Intentional fall-through */
-		case XML_ELEMENT_NODE:
-		case XML_DOCUMENT_NODE:
-		case XML_HTML_DOCUMENT_NODE:
-		case XML_CDATA_SECTION_NODE:
-		case XML_PI_NODE:
-		case XML_COMMENT_NODE:
-		    xmlXPathNodeSetAddUnique(list, cur);
-		    break;
-		case XML_DTD_NODE:
-		    /* Unlink the DTD, it's still reachable
-		     * using doc->intSubset */
-		    if (cur->next != NULL)
-			cur->next->prev = cur->prev;
-		    if (cur->prev != NULL)
-			cur->prev->next = cur->next;
-		    break;
-		case XML_NAMESPACE_DECL:
-		    break;
-		default:
-#ifdef WITH_XSLT_DEBUG_PROCESS
-		    XSLT_TRACE(ctxt,XSLT_TRACE_APPLY_TEMPLATES,xsltGenericDebug(xsltGenericDebugContext,
-		     "xsltApplyTemplates: skipping cur type %d\n",
-				     cur->type));
-#endif
-		    delNode = cur;
-	    }
+            if (IS_XSLT_REAL_NODE(cur))
+		xmlXPathNodeSetAddUnique(list, cur);
 	    cur = cur->next;
-	    if (delNode != NULL) {
-#ifdef WITH_XSLT_DEBUG_PROCESS
-		XSLT_TRACE(ctxt,XSLT_TRACE_APPLY_TEMPLATES,xsltGenericDebug(xsltGenericDebugContext,
-		     "xsltApplyTemplates: removing ignorable blank cur\n"));
-#endif
-		xmlUnlinkNode(delNode);
-		xmlFreeNode(delNode);
-		delNode = NULL;
-	    }
 	}
     }
 
