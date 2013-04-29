$NetBSD: patch-storage_myisam_mi__check.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_check.c.orig	2013-04-28 14:00:51.000000000 +0000
+++ storage/myisam/mi_check.c
@@ -1159,7 +1159,7 @@ int chk_data_link(MI_CHECK *param, MI_IN
 	  if (param->testflag & (T_EXTEND | T_MEDIUM | T_VERBOSE))
 	  {
 	    if (_mi_rec_check(info,record, info->rec_buff,block_info.rec_len,
-                              test(info->s->calc_checksum)))
+                              my_test(info->s->calc_checksum)))
 	    {
 	      mi_check_print_error(param,"Found wrong packed record at %s",
 			  llstr(start_recpos,llbuff));
@@ -2386,7 +2386,7 @@ int mi_repair_by_sort(MI_CHECK *param, r
       if (keyseg[i].flag & HA_SPACE_PACK)
 	sort_param.key_length+=get_pack_length(keyseg[i].length);
       if (keyseg[i].flag & (HA_BLOB_PART | HA_VAR_LENGTH_PART))
-	sort_param.key_length+=2 + test(keyseg[i].length >= 127);
+	sort_param.key_length+=2 + my_test(keyseg[i].length >= 127);
       if (keyseg[i].flag & HA_NULL_PART)
 	sort_param.key_length++;
     }
@@ -2877,7 +2877,7 @@ int mi_repair_parallel(MI_CHECK *param, 
       if (keyseg->flag & HA_SPACE_PACK)
         sort_param[i].key_length+=get_pack_length(keyseg->length);
       if (keyseg->flag & (HA_BLOB_PART | HA_VAR_LENGTH_PART))
-        sort_param[i].key_length+=2 + test(keyseg->length >= 127);
+        sort_param[i].key_length+=2 + my_test(keyseg->length >= 127);
       if (keyseg->flag & HA_NULL_PART)
         sort_param[i].key_length++;
     }
@@ -2894,7 +2894,7 @@ int mi_repair_parallel(MI_CHECK *param, 
   sort_info.total_keys=i;
   sort_param[0].master= 1;
   sort_param[0].fix_datafile= (my_bool)(! rep_quick);
-  sort_param[0].calc_checksum= test(param->testflag & T_CALC_CHECKSUM);
+  sort_param[0].calc_checksum= my_test(param->testflag & T_CALC_CHECKSUM);
 
   if (!ftparser_alloc_param(info))
     goto err;
@@ -3564,7 +3564,7 @@ static int sort_get_next_record(MI_SORT_
                             sort_param->find_length,
                             (param->testflag & T_QUICK) &&
                             sort_param->calc_checksum &&
-                            test(info->s->calc_checksum)))
+                            my_test(info->s->calc_checksum)))
 	  {
 	    mi_check_print_info(param,"Found wrong packed record at %s",
 				llstr(sort_param->start_recpos,llbuff));
@@ -3722,7 +3722,7 @@ int sort_write_record(MI_SORT_PARAM *sor
 
       do
       {
-	block_length=reclength+ 3 + test(reclength >= (65520-3));
+	block_length=reclength+ 3 + my_test(reclength >= (65520-3));
 	if (block_length < share->base.min_block_length)
 	  block_length=share->base.min_block_length;
 	info->update|=HA_STATE_WRITE_AT_END;
@@ -4641,7 +4641,7 @@ static ha_checksum mi_byte_checksum(cons
   const uchar *end=buf+length;
   for (crc=0; buf != end; buf++)
     crc=((crc << 1) + *((uchar*) buf)) +
-      test(crc & (((ha_checksum) 1) << (8*sizeof(ha_checksum)-1)));
+      my_test(crc & (((ha_checksum) 1) << (8*sizeof(ha_checksum)-1)));
   return crc;
 }
 
