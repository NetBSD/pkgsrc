$NetBSD: patch-src_plugins_contrib_dragscroll_dragscrollcfg.h,v 1.1 2022/08/15 20:40:11 he Exp $

Remove unprotected non-portable asm() as per upstream svn.
Ref. https://forums.codeblocks.org/index.php?topic=23761.0

--- src/plugins/contrib/dragscroll/dragscrollcfg.h.orig	2020-03-28 12:35:51.000000000 +0000
+++ src/plugins/contrib/dragscroll/dragscrollcfg.h
@@ -35,7 +35,7 @@ class cbDragScrollCfg: public cbConfigur
         wxString GetBitmapBaseName() const;
         void OnApply();
         void OnCancel(){}
-        virtual void InitDialog(){ asm("int3");} /*trap*/
+        virtual void InitDialog(){ } /* was asm("int3"); trap*/
 
         // pointer to owner of the configuration diaglog needed to
         // complete the OnApply/OnCancel EndModal() logic
