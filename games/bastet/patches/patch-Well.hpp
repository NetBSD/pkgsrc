$NetBSD: patch-Well.hpp,v 1.1 2016/12/22 11:36:35 joerg Exp $

friend declaration should not contain default arguments.

--- Well.hpp.orig	2016-12-22 10:46:03.217308267 +0000
+++ Well.hpp
@@ -30,7 +30,8 @@
 #include <iostream>
 
 namespace Bastet{
-  
+  long Evaluate(const Well *w, int extralines = 0);
+
   class GameOver{}; //used as an exception
 
   class WellLine: public std::bitset<WellWidth>{
@@ -66,7 +67,7 @@ namespace Bastet{
     LinesCompleted Lock(BlockType t, const BlockPosition &p); //permanently adds a tetromino to the well; returns a bitset of 4 bits where return[i]==1 iff line (start of fb)+i is complete
     void ClearLines(const LinesCompleted &lc); //removes the given lines from the well (whether they are completed or not)
     int LockAndClearLines(BlockType t, const BlockPosition &p); //locks, clear lines, returns number of lines cleared
-    friend long Evaluate(const Well *w, int extralines=0); //for BastetBlockChooser
+    friend long Evaluate(const Well *w, int extralines); //for BastetBlockChooser
     std::string PrettyPrint() const;
   };
   
