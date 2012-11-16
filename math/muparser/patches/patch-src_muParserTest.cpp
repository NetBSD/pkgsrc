$NetBSD: patch-src_muParserTest.cpp,v 1.1 2012/11/16 01:04:43 joerg Exp $

--- src/muParserTest.cpp.orig	2012-11-14 13:35:12.000000000 +0000
+++ src/muParserTest.cpp
@@ -1292,25 +1292,25 @@ namespace mu
           // Test copy constructor
           std::vector<mu::Parser> vParser;
           vParser.push_back(*(p1.get()));
-          mu::Parser p2 = vParser[0];   // take parser from vector
+          mu::Parser p2a = vParser[0];   // take parser from vector
         
           // destroy the originals from p2
           vParser.clear();              // delete the vector
           p1.reset(0);
 
-          fVal[2] = p2.Eval();
+          fVal[2] = p2a.Eval();
 
           // Test assignement operator
           // additionally  disable Optimizer this time
-          mu::Parser p3;
-          p3 = p2;
-          p3.EnableOptimizer(false);
-          fVal[3] = p3.Eval();
+          mu::Parser p3a;
+          p3a = p2a;
+          p3a.EnableOptimizer(false);
+          fVal[3] = p3a.Eval();
 
           // Test Eval function for multiple return values
           // use p2 since it has the optimizer enabled!
           int nNum;
-          value_type *v = p2.Eval(nNum);
+          value_type *v = p2a.Eval(nNum);
           fVal[4] = v[nNum-1];
         }
         catch(std::exception &e)
