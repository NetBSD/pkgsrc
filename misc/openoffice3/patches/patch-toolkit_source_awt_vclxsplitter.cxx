$NetBSD: patch-toolkit_source_awt_vclxsplitter.cxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- toolkit/source/awt/vclxsplitter.cxx.orig	2012-06-23 18:25:49.000000000 +0000
+++ toolkit/source/awt/vclxsplitter.cxx
@@ -113,7 +113,7 @@ void SAL_CALL VCLXSplitter::dispose() th
         ::vos::OGuard aGuard( GetMutex() );
 
         EventObject aDisposeEvent;
-        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*this);
+        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*(VCLXDevice *)this);
 //            maTabListeners.disposeAndClear( aDisposeEvent );
     }
 
