$NetBSD: patch-doctype_sgmlnorm.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- doctype/sgmlnorm.hxx~	1997-06-28 20:57:20.000000000 +0000
+++ doctype/sgmlnorm.hxx
@@ -27,7 +27,7 @@ public:
 
   ~SGMLNORM ();
   // hooks into the guts of the field parser
-  virtual CHR* UnifiedName (CHR *tag) const; // for children to play with
+  virtual const CHR* UnifiedName (const CHR *tag) const; // for children to play with
 
   /* SGML helper functions */
   PCHR *parse_tags (CHR *b, GPTYPE len) const;
