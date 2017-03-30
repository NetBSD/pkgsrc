$NetBSD: patch-stubdom_vtpmmgr_tpmrsa.h,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- stubdom/vtpmmgr/tpmrsa.h.orig	2017-03-28 16:12:14.000000000 +0200
+++ stubdom/vtpmmgr/tpmrsa.h	2017-03-28 16:12:26.000000000 +0200
@@ -62,7 +62,7 @@
       unsigned char *output );
 
 /* free tpmrsa key */
-inline void tpmrsa_free( tpmrsa_context *ctx ) {
+static inline void tpmrsa_free( tpmrsa_context *ctx ) {
    mpi_free( &ctx->RN ); mpi_free( &ctx->E  ); mpi_free( &ctx->N  );
 }
 
