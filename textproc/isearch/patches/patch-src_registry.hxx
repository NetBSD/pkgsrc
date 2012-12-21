$NetBSD: patch-src_registry.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- src/registry.hxx~	2000-02-04 23:40:35.000000000 +0000
+++ src/registry.hxx
@@ -79,7 +79,7 @@ public:
   // a comma-delimited list (e.g., tag=val1,val2,val3) into multiple nodes.
   void ProfileLoadFromFile(const STRING& FileName, const STRLIST& Position);
   void ProfileAddFromFile(const STRING& FileName, const STRLIST& Position);
-  void ProfileWrite(ostream& os, const STRING& FileName, const STRLIST& Position);
+  void ProfileWrite(std::ostream& os, const STRING& FileName, const STRLIST& Position);
 //  friend ostream & operator<<(ostream& os, const REGISTRY& Registry);
   ~REGISTRY();
 
@@ -90,7 +90,7 @@ private:
   void AddFromFile(const STRING& FileName);
 //  void Print(ostream& os, const INT Level) const;
 	void fprint(FILE* fp, const INT level = 0) const;
-  void ProfilePrint(ostream& os, const INT Level) const;
+  void ProfilePrint(std::ostream& os, const INT Level) const;
   void GetData(STRLIST *StrlistBuffer);
   void DeleteChildren();
   REGISTRY* FindNode(const STRING& Position);
