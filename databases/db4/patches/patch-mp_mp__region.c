$NetBSD: patch-mp_mp__region.c,v 1.1 2015/09/08 18:51:27 joerg Exp $

--- mp/mp_region.c.orig	2015-08-29 23:35:05.000000000 +0000
+++ mp/mp_region.c
@@ -224,7 +224,7 @@ __memp_init(env, dbmp, reginfo_off, htab
 			     MTX_MPOOL_FILE_BUCKET, 0, &htab[i].mtx_hash)) != 0)
 				return (ret);
 			SH_TAILQ_INIT(&htab[i].hash_bucket);
-			atomic_init(&htab[i].hash_page_dirty, 0);
+			db_atomic_init(&htab[i].hash_page_dirty, 0);
 		}
 
 		/*
@@ -269,7 +269,7 @@ __memp_init(env, dbmp, reginfo_off, htab
 		hp->mtx_hash = (mtx_base == MUTEX_INVALID) ? MUTEX_INVALID :
 		    mtx_base + i;
 		SH_TAILQ_INIT(&hp->hash_bucket);
-		atomic_init(&hp->hash_page_dirty, 0);
+		db_atomic_init(&hp->hash_page_dirty, 0);
 #ifdef HAVE_STATISTICS
 		hp->hash_io_wait = 0;
 		hp->hash_frozen = hp->hash_thawed = hp->hash_frozen_freed = 0;
