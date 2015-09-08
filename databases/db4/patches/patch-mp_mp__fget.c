$NetBSD: patch-mp_mp__fget.c,v 1.1 2015/09/08 18:51:27 joerg Exp $

--- mp/mp_fget.c.orig	2015-08-29 23:35:11.000000000 +0000
+++ mp/mp_fget.c
@@ -617,7 +617,7 @@ alloc:		/* Allocate a new buffer header 
 
 		/* Initialize enough so we can call __memp_bhfree. */
 		alloc_bhp->flags = 0;
-		atomic_init(&alloc_bhp->ref, 1);
+		db_atomic_init(&alloc_bhp->ref, 1);
 #ifdef DIAGNOSTIC
 		if ((uintptr_t)alloc_bhp->buf & (sizeof(size_t) - 1)) {
 			__db_errx(env,
@@ -911,7 +911,7 @@ alloc:		/* Allocate a new buffer header 
 			MVCC_MPROTECT(bhp->buf, mfp->stat.st_pagesize,
 			    PROT_READ);
 
-		atomic_init(&alloc_bhp->ref, 1);
+		db_atomic_init(&alloc_bhp->ref, 1);
 		MUTEX_LOCK(env, alloc_bhp->mtx_buf);
 		alloc_bhp->priority = bhp->priority;
 		alloc_bhp->pgno = bhp->pgno;
