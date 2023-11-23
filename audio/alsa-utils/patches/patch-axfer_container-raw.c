$NetBSD: patch-axfer_container-raw.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/container-raw.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/container-raw.c
@@ -13,10 +13,10 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
-static int raw_builder_pre_process(struct container_context *,
-				   snd_pcm_format_t *,
-				   unsigned int *,
-				   unsigned int *,
+static int raw_builder_pre_process(struct container_context *cntr ATTRIBUTE_UNUSED,
+				   snd_pcm_format_t *format ATTRIBUTE_UNUSED,
+				   unsigned int *samples_per_frame ATTRIBUTE_UNUSED,
+				   unsigned int *frames_per_second ATTRIBUTE_UNUSED,
 				   uint64_t *byte_count)
 {
 	*byte_count = UINT64_MAX;
@@ -25,9 +25,9 @@ static int raw_builder_pre_process(struc
 }
 
 static int raw_parser_pre_process(struct container_context *cntr,
-				  snd_pcm_format_t *,
-				  unsigned int *,
-				  unsigned int *,
+				  snd_pcm_format_t *format ATTRIBUTE_UNUSED,
+				  unsigned int *samples_per_frame ATTRIBUTE_UNUSED,
+				  unsigned int *frames_per_second ATTRIBUTE_UNUSED,
 				  uint64_t *byte_count)
 {
 	struct stat buf = {0};
