$NetBSD: patch-saml.c,v 1.1 2014/07/22 09:47:37 manu Exp $

When iterating to the root of the assertiin, make sure we do not try to 
work on XML_DOCUMENT_NODE type node, only on XML_ELEMENT_NODE.

--- saml.c.orig	2012-11-08 09:36:54.000000000 +0100
+++ saml.c	2014-02-10 05:52:14.000000000 +0100
@@ -385,9 +385,11 @@
 		if (node->parent == NULL)
 			break;
 		node = node->parent;
 
-	} while ((node != node->parent) && (node != NULL));
+	} while ((node != node->parent) &&
+		 (node != NULL) &&
+		 (node->type == XML_ELEMENT_NODE));
 
 	saml_error(params, 0, "SAML assertion signature verification "
 		   "failure (error %d)", error);
 	return EACCES;
