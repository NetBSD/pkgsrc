$NetBSD: patch-doctype_medline.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- doctype/medline.hxx~	1996-07-10 18:54:09.000000000 +0000
+++ doctype/medline.hxx
@@ -25,7 +25,7 @@ public:
 		PSTRING StringBuffer);
 	~MEDLINE();
 // hooks into the guts of the field parser
-	virtual PCHR UnifiedName (PCHR tag) const; // for children to play with
+	virtual PKCHR UnifiedName (PKCHR tag) const; // for children to play with
 };
 typedef MEDLINE* PMEDLINE;
 
