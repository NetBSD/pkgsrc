$NetBSD: patch-libgda_gda-entity-field.c,v 1.1 2012/05/04 16:08:09 joerg Exp $

--- libgda/gda-entity-field.c.orig	2012-04-27 17:18:10.000000000 +0000
+++ libgda/gda-entity-field.c
@@ -109,12 +109,10 @@ gda_entity_field_get_dict_type (GdaEntit
 void
 gda_entity_field_set_dict_type (GdaEntityField *iface, GdaDictType *type)
 {
-	g_return_val_if_fail (iface && GDA_IS_ENTITY_FIELD (iface), NULL);
+	g_return_if_fail (iface && GDA_IS_ENTITY_FIELD (iface));
 
 	if (GDA_ENTITY_FIELD_GET_IFACE (iface)->set_dict_type)
 		return (GDA_ENTITY_FIELD_GET_IFACE (iface)->set_dict_type) (iface, type);
-	
-	return NULL;
 }
 
 /**
