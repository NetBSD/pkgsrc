$NetBSD: patch-xpointer.c,v 1.4 2016/12/27 02:34:34 sevan Exp $

CVE-2016-4658
https://git.gnome.org/browse/libxml2/commit/?id=c1d1f7121194036608bf555f08d3062a36fd344b

CVE-2016-5131
https://git.gnome.org/browse/libxml2/commit/?id=9ab01a277d71f54d3143c2cf333c5c2e9aaedd9e

--- xpointer.c.orig	2016-12-27 02:19:03.000000000 +0000
+++ xpointer.c
@@ -1295,8 +1295,6 @@ xmlXPtrNewContext(xmlDocPtr doc, xmlNode
     ret->here = here;
     ret->origin = origin;
 
-    xmlXPathRegisterFunc(ret, (xmlChar *)"range-to",
-	                 xmlXPtrRangeToFunction);
     xmlXPathRegisterFunc(ret, (xmlChar *)"range",
 	                 xmlXPtrRangeFunction);
     xmlXPathRegisterFunc(ret, (xmlChar *)"range-inside",
@@ -2206,76 +2204,14 @@ xmlXPtrRangeInsideFunction(xmlXPathParse
  * @nargs:  the number of args
  *
  * Implement the range-to() XPointer function
+ *
+ * Obsolete. range-to is not a real function but a special type of location
+ * step which is handled in xpath.c.
  */
 void
-xmlXPtrRangeToFunction(xmlXPathParserContextPtr ctxt, int nargs) {
-    xmlXPathObjectPtr range;
-    const xmlChar *cur;
-    xmlXPathObjectPtr res, obj;
-    xmlXPathObjectPtr tmp;
-    xmlLocationSetPtr newset = NULL;
-    xmlNodeSetPtr oldset;
-    int i;
-
-    if (ctxt == NULL) return;
-    CHECK_ARITY(1);
-    /*
-     * Save the expression pointer since we will have to evaluate
-     * it multiple times. Initialize the new set.
-     */
-    CHECK_TYPE(XPATH_NODESET);
-    obj = valuePop(ctxt);
-    oldset = obj->nodesetval;
-    ctxt->context->node = NULL;
-
-    cur = ctxt->cur;
-    newset = xmlXPtrLocationSetCreate(NULL);
-
-    for (i = 0; i < oldset->nodeNr; i++) {
-	ctxt->cur = cur;
-
-	/*
-	 * Run the evaluation with a node list made of a single item
-	 * in the nodeset.
-	 */
-	ctxt->context->node = oldset->nodeTab[i];
-	tmp = xmlXPathNewNodeSet(ctxt->context->node);
-	valuePush(ctxt, tmp);
-
-	xmlXPathEvalExpr(ctxt);
-	CHECK_ERROR;
-
-	/*
-	 * The result of the evaluation need to be tested to
-	 * decided whether the filter succeeded or not
-	 */
-	res = valuePop(ctxt);
-	range = xmlXPtrNewRangeNodeObject(oldset->nodeTab[i], res);
-	if (range != NULL) {
-	    xmlXPtrLocationSetAdd(newset, range);
-	}
-
-	/*
-	 * Cleanup
-	 */
-	if (res != NULL)
-	    xmlXPathFreeObject(res);
-	if (ctxt->value == tmp) {
-	    res = valuePop(ctxt);
-	    xmlXPathFreeObject(res);
-	}
-
-	ctxt->context->node = NULL;
-    }
-
-    /*
-     * The result is used as the new evaluation set.
-     */
-    xmlXPathFreeObject(obj);
-    ctxt->context->node = NULL;
-    ctxt->context->contextSize = -1;
-    ctxt->context->proximityPosition = -1;
-    valuePush(ctxt, xmlXPtrWrapLocationSet(newset));
+xmlXPtrRangeToFunction(xmlXPathParserContextPtr ctxt,
+                       int nargs ATTRIBUTE_UNUSED) {
+    XP_ERROR(XPATH_EXPR_ERROR);
 }
 
 /**
