$NetBSD: patch-include_libxml_xpath.h,v 1.1 2011/11/01 19:21:06 spz Exp $

--- include/libxml/xpath.h.orig	2010-10-12 06:25:32.000000000 +0000
+++ include/libxml/xpath.h
@@ -68,7 +68,8 @@ typedef enum {
     XPATH_UNDEF_PREFIX_ERROR,
     XPATH_ENCODING_ERROR,
     XPATH_INVALID_CHAR_ERROR,
-    XPATH_INVALID_CTXT
+    XPATH_INVALID_CTXT,
+    XPATH_STACK_ERROR
 } xmlXPathError;
 
 /*
@@ -380,6 +381,8 @@ struct _xmlXPathParserContext {
     xmlXPathCompExprPtr comp;		/* the precompiled expression */
     int xptr;				/* it this an XPointer expression */
     xmlNodePtr         ancestor;	/* used for walking preceding axis */
+
+    int              valueFrame;	/* used to limit Pop on the stack */
 };
 
 /************************************************************************
