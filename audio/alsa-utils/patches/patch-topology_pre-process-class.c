$NetBSD: patch-topology_pre-process-class.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/pre-process-class.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/pre-process-class.c
@@ -127,7 +127,7 @@ snd_config_t *tplg_class_lookup(struct t
 }
 
 /* find the attribute config by name in the class definition */
-snd_config_t *tplg_class_find_attribute_by_name(struct tplg_pre_processor *,
+snd_config_t *tplg_class_find_attribute_by_name(struct tplg_pre_processor *tplg_p ATTRIBUTE_UNUSED,
 						snd_config_t *class, const char *name)
 {
 	snd_config_t *attr = NULL;
@@ -152,7 +152,7 @@ snd_config_t *tplg_class_find_attribute_
 }
 
 /* get the name of the attribute that must have a unique value in the object instance */
-const char *tplg_class_get_unique_attribute_name(struct tplg_pre_processor *,
+const char *tplg_class_get_unique_attribute_name(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 						 snd_config_t *class)
 {
 	snd_config_t *unique;
@@ -177,7 +177,7 @@ const char *tplg_class_get_unique_attrib
 }
 
 /* get attribute type from the definition */
-snd_config_type_t tplg_class_get_attribute_type(struct tplg_pre_processor *,
+snd_config_type_t tplg_class_get_attribute_type(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 						snd_config_t *attr)
 {
 	snd_config_t *type;
@@ -208,7 +208,7 @@ snd_config_type_t tplg_class_get_attribu
 }
 
 /* get token_ref for attribute with name attr_name in the class */
-const char *tplg_class_get_attribute_token_ref(struct tplg_pre_processor *,
+const char *tplg_class_get_attribute_token_ref(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 					       snd_config_t *class, const char *attr_name)
 {
 	snd_config_t *attributes, *attr, *token_ref;
@@ -235,7 +235,7 @@ const char *tplg_class_get_attribute_tok
 }
 
 /* convert a valid attribute string value to the corresponding tuple value */
-long tplg_class_attribute_valid_tuple_value(struct tplg_pre_processor *,
+long tplg_class_attribute_valid_tuple_value(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 					    snd_config_t *class, snd_config_t *attr)
 {
 
