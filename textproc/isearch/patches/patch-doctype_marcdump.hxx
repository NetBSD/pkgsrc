$NetBSD: patch-doctype_marcdump.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- doctype/marcdump.hxx~	1998-05-19 21:01:18.000000000 +0000
+++ doctype/marcdump.hxx
@@ -19,7 +19,7 @@ class MARCDUMP 
 public:
     MARCDUMP(PIDBOBJ DbParent);
     void AddFieldDefs();
-    CHR* UnifiedName (CHR *tag);
+    const CHR* UnifiedName (const CHR *tag);
     void ParseRecords(const RECORD& FileRecord);
     void ParseFields(RECORD *NewRecord);
 
