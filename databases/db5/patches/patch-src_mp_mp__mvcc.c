$NetBSD: patch-src_mp_mp__mvcc.c,v 1.1 2015/09/08 18:51:28 joerg Exp $

--- src/mp/mp_mvcc.c.orig	2015-09-02 11:12:47.000000000 +0000
+++ src/mp/mp_mvcc.c
@@ -276,7 +276,7 @@ __memp_bh_freeze(dbmp, infop, hp, bhp, n
 #else
 	memcpy(frozen_bhp, bhp, SSZA(BH, buf));
 #endif
-	atomic_init(&frozen_bhp->ref, 0);
+	db_atomic_init(&frozen_bhp->ref, 0);
 	if (mutex != MUTEX_INVALID)
 		frozen_bhp->mtx_buf = mutex;
 	else if ((ret = __mutex_alloc(env, MTX_MPOOL_BH,
@@ -428,7 +428,7 @@ __memp_bh_thaw(dbmp, infop, hp, frozen_b
 #endif
 		alloc_bhp->mtx_buf = mutex;
 		MUTEX_LOCK(env, alloc_bhp->mtx_buf);
-		atomic_init(&alloc_bhp->ref, 1);
+		db_atomic_init(&alloc_bhp->ref, 1);
 		F_CLR(alloc_bhp, BH_FROZEN);
 	}
 
