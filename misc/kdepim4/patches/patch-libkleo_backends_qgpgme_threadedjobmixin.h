$NetBSD: patch-libkleo_backends_qgpgme_threadedjobmixin.h,v 1.1 2012/11/11 22:29:14 joerg Exp $

--- libkleo/backends/qgpgme/threadedjobmixin.h.orig	2012-11-09 13:05:24.000000000 +0000
+++ libkleo/backends/qgpgme/threadedjobmixin.h
@@ -143,7 +143,7 @@ namespace _detail {
 
     void lateInitialization() {
       assert( m_ctx );
-      connect( &m_thread, SIGNAL(finished()), this, SLOT(slotFinished()) );
+      this->connect( &m_thread, SIGNAL(finished()), this, SLOT(slotFinished()) );
       m_ctx->setProgressProvider( this );
     }
 
