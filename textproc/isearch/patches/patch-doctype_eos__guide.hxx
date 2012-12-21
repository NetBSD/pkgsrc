$NetBSD: patch-doctype_eos__guide.hxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- doctype/eos_guide.hxx~	2000-09-06 18:20:30.000000000 +0000
+++ doctype/eos_guide.hxx
@@ -22,7 +22,7 @@ public:
   ~EOS_GUIDE();
 
 private:
-  INT TagMatch(char* tag, char* tagType) const;
+  INT TagMatch(const char* tag, const char* tagType) const;
   STRING DocSource;
 };
 
