$NetBSD: patch-sw_inc_viewsh.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- sw/inc/viewsh.hxx.orig	2014-01-18 18:39:49.000000000 +0000
+++ sw/inc/viewsh.hxx
@@ -109,7 +109,7 @@ class SW_DLLPUBLIC ViewShell : public Ri
 
 
     // Set SwVisArea in order to enable clean formatting before printing.
-    friend void SetSwVisArea( ViewShell *pSh, const SwRect &, sal_Bool bPDFExport = sal_False );
+    friend void SetSwVisArea( ViewShell *pSh, const SwRect &, sal_Bool bPDFExport );
 
     static BitmapEx*    mpReplaceBmp;    ///< replaced display of still loaded images
     static BitmapEx*    mpErrorBmp;      ///< error display of missed images
@@ -566,6 +566,8 @@ public:
     virtual void SetShowHeaderFooterSeparator( FrameControlType eControl, bool bShow ) { if ( eControl == Header ) mbShowHeaderSeparator = bShow; else mbShowFooterSeparator = bShow; }
 };
 
+void SetSwVisArea( ViewShell *pSh, const SwRect &, sal_Bool bPDFExport = sal_False );
+
 //---- class CurrShell manages global ShellPointer -------------------
 
 class CurrShell
