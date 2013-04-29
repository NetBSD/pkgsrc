$NetBSD: patch-storage_myisam_mi__create.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_create.c.orig	2013-04-28 14:00:49.000000000 +0000
+++ storage/myisam/mi_create.c
@@ -134,7 +134,7 @@ int mi_create(const char *name,uint keys
 	pack_reclength++;
         min_pack_length++;
         /* We must test for 257 as length includes pack-length */
-        if (test(rec->length >= 257))
+        if (my_test(rec->length >= 257))
 	{
 	  long_varchar_count++;
 	  pack_reclength+= 2;			/* May be packed on 3 bytes */
@@ -193,7 +193,7 @@ int mi_create(const char *name,uint keys
   packed=(packed+7)/8;
   if (pack_reclength != INT_MAX32)
     pack_reclength+= reclength+packed +
-      test(test_all_bits(options, HA_OPTION_CHECKSUM | HA_OPTION_PACK_RECORD));
+      my_test(test_all_bits(options, HA_OPTION_CHECKSUM | HA_OPTION_PACK_RECORD));
   min_pack_length+=packed;
 
   if (!ci->data_file_length && ci->max_rows)
@@ -544,7 +544,7 @@ int mi_create(const char *name,uint keys
   share.base.records=ci->max_rows;
   share.base.reloc=  ci->reloc_rows;
   share.base.reclength=real_reclength;
-  share.base.pack_reclength=reclength+ test(options & HA_OPTION_CHECKSUM);
+  share.base.pack_reclength=reclength+ my_test(options & HA_OPTION_CHECKSUM);
   share.base.max_pack_length=pack_reclength;
   share.base.min_pack_length=min_pack_length;
   share.base.pack_bits=packed;
