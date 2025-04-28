$NetBSD: patch-dict-generate.cpp,v 1.1 2025/04/28 20:44:38 tnn Exp $

* https://github.com/tsyrogit/zxcvbn-c/commit/b9f30993c88d9057d7d95a1b059989f7853fd1b0
* https://github.com/tsyrogit/zxcvbn-c/commit/92c6ea875231876ca264187326ce2d615d5ad543

--- dict-generate.cpp.orig	2025-04-28 20:39:40.248646721 +0000
+++ dict-generate.cpp
@@ -22,6 +22,8 @@
  *
  **********************************************************************************/
 
+#include <algorithm>
+#include <cstdint>
 #include <iostream>
 #include <string>
 #include <fstream>
@@ -387,7 +389,7 @@ typedef map<string, Entry> EntryMap_t;
 typedef list<string> StringList_t;
 typedef list<NodeSPtr> NodeList_t;
 typedef set<StringInt> StringIntSet_t;
-typedef basic_string<int> StringOfInts;
+typedef vector<int> StringOfInts;
 typedef vector<unsigned int> UintVect;
 typedef vector<uint64_t> Uint64Vect;
 typedef vector<StringInt *> StrIntPtrVect_t;
@@ -601,17 +603,14 @@ static void ScanTrieForOrder(EntryMap_t
 static void ReduceTrie(NodeSPtr Root)
 {
     int Height;
-    int cnt=0, del=0;
     Root->CalcCheck();
 
     NodeSPtr pNode = Root;
     for(Height = Root->CalcHeight(); Height >= 0; --Height)
     {
         // Get a list of all nodes at given height
-        int x=0;
         NodeList_t Lst;
         AddToListAtHeight(Lst, Root, Height);
-        cnt += Lst.size();
 
         NodeList_t::iterator Ita, Itb;
         for(Ita = Lst.begin(); Ita != Lst.end(); ++Ita)
@@ -631,7 +630,6 @@ static void ReduceTrie(NodeSPtr Root)
                         // Remove the 2nd node from the scanning list to as it will
                         // get deleted by the sharing (as using std::shared_ptr)
                         Parentb->ChangeChild(*Ita, *Itb);
-                        ++x;++del;
                         Itb = Lst.erase(Itb);
                     }
                     else
@@ -741,7 +739,7 @@ static int CheckReduction(StringIntVect_
         {
             char Tmp[20];
             Ranks[b].i = It->second.mRank;
-            sprintf(Tmp, "%d: ", n);
+            snprintf(Tmp, sizeof(Tmp), "%d: ", n);
             Ranks[b].s = string(Tmp) + Text;
         }
         // Try to find a non-existant word
@@ -868,15 +866,14 @@ void CreateArrays(NodeSPtr Root, StringI
     for(Itc = Root->ChildBegin(); Itc != Root->ChildEnd(); ++Itc)
     {
         int i = Itc->second->GetAddr();
-        Chld += i;
+        Chld.push_back(i);
     }
     // Find where in pointer array the child pointer string is
-    StringOfInts::size_type x = ChildAddrs.find(Chld);
-    if (x == StringOfInts::npos)
+    StringOfInts::size_type x = search(ChildAddrs.begin(), ChildAddrs.end(), Chld.begin(), Chld.end()) - ChildAddrs.begin();
+    if (x == ChildAddrs.size())
     {
         // Not found, add it
-        x = ChildAddrs.length();
-        ChildAddrs += Chld;
+        ChildAddrs.insert(ChildAddrs.end(), Chld.begin(), Chld.end());
     }
     // Val will contain the final node data
     uint64_t Val = Its->i;
