$NetBSD: patch-xpath.c,v 1.3 2018/08/09 18:44:13 snj Exp $

Fix CVE-2018-14404.

https://gitlab.gnome.org/GNOME/libxml2/commit/a436374994c47b12d5de1b8b1d191a098fa23594

--- xpath.c.orig	2017-12-02 00:58:10.000000000 -0800
+++ xpath.c	2018-08-09 11:37:59.278508181 -0700
@@ -13297,9 +13297,8 @@ xmlXPathCompOpEval(xmlXPathParserContext
 		return(0);
 	    }
             xmlXPathBooleanFunction(ctxt, 1);
-            arg1 = valuePop(ctxt);
-            arg1->boolval &= arg2->boolval;
-            valuePush(ctxt, arg1);
+            if (ctxt->value != NULL)
+                ctxt->value->boolval &= arg2->boolval;
 	    xmlXPathReleaseObject(ctxt->context, arg2);
             return (total);
         case XPATH_OP_OR:
@@ -13323,9 +13322,8 @@ xmlXPathCompOpEval(xmlXPathParserContext
 		return(0);
 	    }
             xmlXPathBooleanFunction(ctxt, 1);
-            arg1 = valuePop(ctxt);
-            arg1->boolval |= arg2->boolval;
-            valuePush(ctxt, arg1);
+            if (ctxt->value != NULL)
+                ctxt->value->boolval |= arg2->boolval;
 	    xmlXPathReleaseObject(ctxt->context, arg2);
             return (total);
         case XPATH_OP_EQUAL:
