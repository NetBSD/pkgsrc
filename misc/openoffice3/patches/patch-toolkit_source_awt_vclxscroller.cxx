$NetBSD: patch-toolkit_source_awt_vclxscroller.cxx,v 1.1 2012/06/29 12:36:39 joerg Exp $

--- toolkit/source/awt/vclxscroller.cxx.orig	2012-06-23 18:22:34.000000000 +0000
+++ toolkit/source/awt/vclxscroller.cxx
@@ -75,7 +75,7 @@ void SAL_CALL VCLXScroller::dispose() th
         ::vos::OGuard aGuard( GetMutex() );
 
         EventObject aDisposeEvent;
-        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*this);
+        aDisposeEvent.Source = W3K_EXPLICIT_CAST (*(VCLXDevice *)this);
 //            maTabListeners.disposeAndClear( aDisposeEvent );
     }
 
