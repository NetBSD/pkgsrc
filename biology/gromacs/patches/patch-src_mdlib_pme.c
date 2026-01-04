$NetBSD: patch-src_mdlib_pme.c,v 1.1 2026/01/04 00:03:57 wiz Exp $

Use proper type.

--- src/mdlib/pme.c.orig	2026-01-04 00:01:45.206745929 +0000
+++ src/mdlib/pme.c
@@ -2082,7 +2082,7 @@ int gmx_pme_init(gmx_pme_t *         pme
         {
 #ifdef GMX_MPI
             pme->mpi_comm_d[0] = pme->mpi_comm;
-            pme->mpi_comm_d[1] = NULL;
+            pme->mpi_comm_d[1] = 0;
 #endif
             pme->ndecompdim = 1;
             pme->nodeid_major = pme->nodeid;
@@ -2092,7 +2092,7 @@ int gmx_pme_init(gmx_pme_t *         pme
         else if (nnodes_major == 1)
         {
 #ifdef GMX_MPI
-            pme->mpi_comm_d[0] = NULL;
+            pme->mpi_comm_d[0] = 0;
             pme->mpi_comm_d[1] = pme->mpi_comm;
 #endif
             pme->ndecompdim = 1;
