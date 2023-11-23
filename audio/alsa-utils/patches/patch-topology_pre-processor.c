$NetBSD: patch-topology_pre-processor.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- topology/pre-processor.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ topology/pre-processor.c
@@ -231,8 +231,9 @@ void tplg_pp_config_debug(struct tplg_pr
 	snd_config_save(cfg, tplg_pp->dbg_output);
 }
 #else
-void tplg_pp_debug(char *, ...) {}
-void tplg_pp_config_debug(struct tplg_pre_processor *, snd_config_t *){}
+void tplg_pp_debug(char *fmt ATTRIBUTE_UNUSED, ...) {}
+void tplg_pp_config_debug(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
+			  snd_config_t *cfg ATTRIBUTE_UNUSED) {}
 #endif
 
 static int pre_process_config(struct tplg_pre_processor *tplg_pp, snd_config_t *cfg)
@@ -640,8 +641,9 @@ static int pre_process_includes_all(stru
 }
 
 /* duplicate the existing objects in src into dest and update with new attribute */
-static int pre_process_add_objects(struct tplg_pre_processor *, int *object_count,
-				   snd_config_t *src, snd_config_t *dest, snd_config_t *attr_cfg)
+static int pre_process_add_objects(struct tplg_pre_processor *tplg_pp ATTRIBUTE_UNUSED,
+				   int *object_count, snd_config_t *src,
+				   snd_config_t *dest, snd_config_t *attr_cfg)
 {
 	snd_config_iterator_t i, next;
 	int ret;
