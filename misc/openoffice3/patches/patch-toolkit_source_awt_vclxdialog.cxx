$NetBSD: patch-toolkit_source_awt_vclxdialog.cxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- toolkit/source/awt/vclxdialog.cxx.orig	2012-06-23 18:17:00.000000000 +0000
+++ toolkit/source/awt/vclxdialog.cxx
@@ -109,7 +109,7 @@ void SAL_CALL VCLXDialog::dispose() thro
         ::vos::OGuard aGuard( GetMutex() );
 
         ::com::sun::star::lang::EventObject aDisposeEvent;
-        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*this);
+        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*(VCLXDevice *)this);
 //            maTabListeners.disposeAndClear( aDisposeEvent );
     }
 
