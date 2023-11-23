$NetBSD: patch-topology_pre-process-object.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/pre-process-object.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/pre-process-object.c
@@ -31,7 +31,8 @@
 
 /* Parse VendorToken object, create the "SectionVendorToken" and save it */
 int tplg_build_vendor_token_object(struct tplg_pre_processor *tplg_pp,
-				   snd_config_t *obj_cfg, snd_config_t *)
+				   snd_config_t *obj_cfg,
+				   snd_config_t *parent ATTRIBUTE_UNUSED)
 {
 	snd_config_iterator_t i, next;
 	snd_config_t *vtop, *n, *obj;
@@ -196,7 +197,7 @@ int tplg_build_data_object(struct tplg_p
 	return tplg_parent_update(tplg_pp, parent, "data", name);
 }
 
-static int tplg_create_config_template(struct tplg_pre_processor *,
+static int tplg_create_config_template(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 				       snd_config_t **template,
 				       const struct config_template_items *items)
 {
@@ -499,7 +500,7 @@ min_max_check:
 }
 
 /* get object's name attribute value */
-const char *tplg_object_get_name(struct tplg_pre_processor *,
+const char *tplg_object_get_name(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 				 snd_config_t *object)
 {
 	snd_config_t *cfg;
@@ -518,7 +519,7 @@ const char *tplg_object_get_name(struct 
 }
 
 /* look up the instance of object in a config */
-static snd_config_t *tplg_object_lookup_in_config(struct tplg_pre_processor *,
+static snd_config_t *tplg_object_lookup_in_config(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 						  snd_config_t *class, const char *type,
 						  const char *class_name, const char *id)
 {
@@ -977,7 +978,7 @@ template:
 }
 
 static int tplg_build_generic_object(struct tplg_pre_processor *tplg_pp, snd_config_t *obj_cfg,
-				     snd_config_t *)
+				     snd_config_t *parent ATTRIBUTE_UNUSED)
 {
 	snd_config_t *wtop;
 	const char *name;
@@ -1090,7 +1091,7 @@ const struct build_function_map object_b
 	 NULL, &pcm_caps_config},
 };
 
-static const struct build_function_map *tplg_object_get_map(struct tplg_pre_processor *,
+static const struct build_function_map *tplg_object_get_map(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 							    snd_config_t *obj)
 {
 	snd_config_iterator_t first;
@@ -1145,7 +1146,7 @@ snd_config_t *tplg_object_get_section(st
 }
 
 /* return 1 if attribute not found in search_config, 0 on success and negative value on error */
-static int tplg_object_copy_and_add_param(struct tplg_pre_processor *,
+static int tplg_object_copy_and_add_param(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 					  snd_config_t *obj,
 					  snd_config_t *attr_cfg,
 					  snd_config_t *search_config)
@@ -1351,8 +1352,8 @@ static int tplg_object_pre_process_child
 	return 0;
 }
 
-static int tplg_construct_object_name(struct tplg_pre_processor *, snd_config_t *obj,
-				      snd_config_t *class_cfg)
+static int tplg_construct_object_name(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
+				      snd_config_t *obj, snd_config_t *class_cfg)
 {
 	snd_config_iterator_t i, next;
 	snd_config_t *args, *n;
@@ -1547,7 +1548,7 @@ static int tplg_object_set_unique_attrib
  * Helper function to get object instance config which is 2 nodes down from class_type config.
  * ex: Get the pointer to the config node with ID "0" from the input config Widget.pga.0 {}
  */
-snd_config_t *tplg_object_get_instance_config(struct tplg_pre_processor *,
+snd_config_t *tplg_object_get_instance_config(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
 					snd_config_t *class_type)
 {
 	snd_config_iterator_t first;
