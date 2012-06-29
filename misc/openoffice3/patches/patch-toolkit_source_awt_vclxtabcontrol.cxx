$NetBSD: patch-toolkit_source_awt_vclxtabcontrol.cxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- toolkit/source/awt/vclxtabcontrol.cxx.orig	2012-06-23 18:31:17.000000000 +0000
+++ toolkit/source/awt/vclxtabcontrol.cxx
@@ -100,7 +100,7 @@ void SAL_CALL VCLXTabControl::dispose( )
         ::vos::OGuard aGuard( GetMutex() );
 
         EventObject aDisposeEvent;
-        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*this);
+        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*(VCLXDevice *)this);
 //            maTabListeners.disposeAndClear( aDisposeEvent );
     }
 
