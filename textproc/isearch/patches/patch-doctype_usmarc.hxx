$NetBSD: patch-doctype_usmarc.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- doctype/usmarc.hxx~	1999-06-05 00:54:00.000000000 +0000
+++ doctype/usmarc.hxx
@@ -50,7 +50,7 @@ private:
   int readBaseAddr(void);
   void readMarcStructure(PRECORD NewRecord);
   int usefulMarcField(char *fieldStr);
-  int compareReg(char *s1, char *s2);
+  int compareReg(const char *s1, const char *s2);
   char findNextTag(char *RecBuffer, int &pos, int &tagPos, int &tagLength);
 };
 
