$NetBSD: patch-pkcs11_gkm_gkm-attributes.c,v 1.1 2025/04/29 21:05:30 tnn Exp $

* Don't conflict with C23 bool.

--- pkcs11/gkm/gkm-attributes.c.orig	2025-04-29 20:17:47.071737705 +0000
+++ pkcs11/gkm/gkm-attributes.c
@@ -34,7 +34,7 @@
 CK_RV
 gkm_attribute_get_bool (CK_ATTRIBUTE_PTR attr, gboolean *value)
 {
-	CK_BBOOL* bool;
+	CK_BBOOL* xbool;
 
 	g_return_val_if_fail (attr, CKR_GENERAL_ERROR);
 	g_return_val_if_fail (value, CKR_GENERAL_ERROR);
@@ -42,8 +42,8 @@ gkm_attribute_get_bool (CK_ATTRIBUTE_PTR
 	if (attr->ulValueLen != sizeof (CK_BBOOL) || attr->pValue == NULL)
 		return CKR_ATTRIBUTE_VALUE_INVALID;
 
-	bool = attr->pValue;
-	*value = *bool ? TRUE : FALSE;
+	xbool = attr->pValue;
+	*value = *xbool ? TRUE : FALSE;
 	return CKR_OK;
 }
 
