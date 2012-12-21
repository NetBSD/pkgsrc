$NetBSD: patch-doctype_filmline.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- doctype/filmline.cxx~	1996-12-21 00:40:37.000000000 +0000
+++ doctype/filmline.cxx
@@ -136,7 +136,7 @@ FILMLINE::FILMLINE (PIDBOBJ DbParent): M
 
 
 // Hooks into the Field parser from Medline
-PCHR FILMLINE::UnifiedName (PCHR tag) const
+PKCHR FILMLINE::UnifiedName (PKCHR tag) const
 {
 #if USE_UNIFIED_NAMES
   static struct {
