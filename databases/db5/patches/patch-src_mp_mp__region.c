$NetBSD: patch-src_mp_mp__region.c,v 1.1 2015/09/08 18:51:28 joerg Exp $

--- src/mp/mp_region.c.orig	2015-09-02 11:12:49.000000000 +0000
+++ src/mp/mp_region.c
@@ -245,7 +245,7 @@ __memp_init(env, dbmp, reginfo_off, htab
 			     MTX_MPOOL_FILE_BUCKET, 0, &htab[i].mtx_hash)) != 0)
 				return (ret);
 			SH_TAILQ_INIT(&htab[i].hash_bucket);
-			atomic_init(&htab[i].hash_page_dirty, 0);
+			db_atomic_init(&htab[i].hash_page_dirty, 0);
 		}
 
 		/*
@@ -302,7 +302,7 @@ no_prealloc:
 		} else
 			hp->mtx_hash = mtx_base + (i % dbenv->mp_mtxcount);
 		SH_TAILQ_INIT(&hp->hash_bucket);
-		atomic_init(&hp->hash_page_dirty, 0);
+		db_atomic_init(&hp->hash_page_dirty, 0);
 #ifdef HAVE_STATISTICS
 		hp->hash_io_wait = 0;
 		hp->hash_frozen = hp->hash_thawed = hp->hash_frozen_freed = 0;
