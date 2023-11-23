$NetBSD: patch-axfer_mapper-single.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/mapper-single.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/mapper-single.c
@@ -62,7 +62,7 @@ static void align_from_vector(void *fram
 
 static int single_pre_process(struct mapper_context *mapper,
 			      struct container_context *cntrs,
-			      unsigned int)
+			      unsigned int cntr_count ATTRIBUTE_UNUSED)
 {
 	struct single_state *state = mapper->private_data;
 	unsigned int bytes_per_buffer;
@@ -110,7 +110,7 @@ static int single_muxer_process_frames(s
 				       void *frame_buf,
 				       unsigned int *frame_count,
 				       struct container_context *cntrs,
-				       unsigned int)
+				       unsigned int cntr_count ATTRIBUTE_UNUSED)
 {
 	struct single_state *state = mapper->private_data;
 	void *src;
@@ -141,7 +141,7 @@ static int single_demuxer_process_frames
 					 void *frame_buf,
 					 unsigned int *frame_count,
 					 struct container_context *cntrs,
-					 unsigned int)
+					 unsigned int cntr_count ATTRIBUTE_UNUSED)
 {
 	struct single_state *state = mapper->private_data;
 	void *dst;
