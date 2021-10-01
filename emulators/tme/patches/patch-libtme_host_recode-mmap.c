$NetBSD: patch-libtme_host_recode-mmap.c,v 1.1 2021/10/01 16:14:48 tsutsui Exp $

- handle PAX_MPROTEXT properly

--- libtme/host/recode-mmap.c.orig	2008-07-01 02:00:53.000000000 +0000
+++ libtme/host/recode-mmap.c
@@ -82,7 +82,12 @@ tme_recode_host_thunks_alloc(struct tme_
 	    size_run,
 	    (PROT_READ
 	     | PROT_WRITE
-	     | PROT_EXEC),
+#ifdef PROT_MPROTECT
+	     | PROT_MPROTECT(PROT_EXEC)
+#else
+	     | PROT_EXEC
+#endif /* PROT_MPROTECT */
+	     ),
 	    (MAP_SHARED
 #ifdef MAP_ANON
 	     | MAP_ANON
