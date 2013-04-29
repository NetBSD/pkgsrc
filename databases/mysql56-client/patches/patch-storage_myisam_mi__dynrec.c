$NetBSD: patch-storage_myisam_mi__dynrec.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_dynrec.c.orig	2013-04-28 14:00:44.000000000 +0000
+++ storage/myisam/mi_dynrec.c
@@ -414,7 +414,7 @@ static int _mi_find_writepos(MI_INFO *in
   {
     /* No deleted blocks;  Allocate a new block */
     *filepos=info->state->data_file_length;
-    if ((tmp=reclength+3 + test(reclength >= (65520-3))) <
+    if ((tmp=reclength+3 + my_test(reclength >= (65520-3))) <
 	info->s->base.min_block_length)
       tmp= info->s->base.min_block_length;
     else
@@ -862,7 +862,7 @@ static int update_dynamic_record(MI_INFO
       if (length < reclength)
       {
 	uint tmp=MY_ALIGN(reclength - length + 3 +
-			  test(reclength >= 65520L),MI_DYN_ALIGN_SIZE);
+			  my_test(reclength >= 65520L),MI_DYN_ALIGN_SIZE);
 	/* Don't create a block bigger than MI_MAX_BLOCK_LENGTH */
 	tmp= MY_MIN(length+tmp, MI_MAX_BLOCK_LENGTH)-length;
 	/* Check if we can extend this block */
@@ -1023,7 +1023,7 @@ uint _mi_rec_pack(MI_INFO *info, registe
 	    pos++;
 	}
 	new_length=(uint) (end-pos);
-	if (new_length +1 + test(rec->length > 255 && new_length > 127)
+	if (new_length +1 + my_test(rec->length > 255 && new_length > 127)
 	    < length)
 	{
 	  if (rec->length > 255 && new_length > 127)
@@ -1143,7 +1143,7 @@ my_bool _mi_rec_check(MI_INFO *info,cons
 	    pos++;
 	}
 	new_length=(uint) (end-pos);
-	if (new_length +1 + test(rec->length > 255 && new_length > 127)
+	if (new_length +1 + my_test(rec->length > 255 && new_length > 127)
 	    < length)
 	{
 	  if (!(flag & bit))
@@ -1195,7 +1195,7 @@ my_bool _mi_rec_check(MI_INFO *info,cons
     else
       to+= length;
   }
-  if (packed_length != (uint) (to - rec_buff) + test(info->s->calc_checksum) ||
+  if (packed_length != (uint) (to - rec_buff) + my_test(info->s->calc_checksum) ||
       (bit != 1 && (flag & ~(bit - 1))))
     goto err;
   if (with_checksum && ((uchar) info->checksum != (uchar) *to))
