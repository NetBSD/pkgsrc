$NetBSD: patch-doctype_filmline.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- doctype/filmline.hxx~	1996-07-10 18:54:08.000000000 +0000
+++ doctype/filmline.hxx
@@ -23,7 +23,7 @@ public:
 		PSTRING StringBuffer);
 	~FILMLINE();
 // hooks into the guts of the Medline field parser
-	PCHR UnifiedName (PCHR tag) const; 
+	PKCHR UnifiedName (PKCHR tag) const; 
 };
 typedef FILMLINE* PFILMLINE;
 
