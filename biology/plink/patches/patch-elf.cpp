$NetBSD: patch-elf.cpp,v 1.1 2012/11/16 00:32:07 joerg Exp $

--- elf.cpp.orig	2012-11-15 12:41:01.000000000 +0000
+++ elf.cpp
@@ -1175,10 +1175,10 @@ void Plink::elfBaseline()
 	  << setw(8) << gcnt << " "
 	  << setw(8) << (double)cnt / (double)gcnt << "\n";
 
-      map<int,int>::iterator i = chr_cnt.begin();
-      while ( i != chr_cnt.end() )
+      map<int,int>::iterator i2 = chr_cnt.begin();
+      while ( i2 != chr_cnt.end() )
 	{
-	  int c = i->first;
+	  int c = i2->first;
 	  int x = chr_cnt.find( c )->second;
 	  int y = chr_gcnt.find( c )->second;
 	  
@@ -1189,7 +1189,7 @@ void Plink::elfBaseline()
 	      << setw(8) << y << " "
 	      << setw(8) << (double)x / (double)y << "\n";
 	  
-	  ++i;
+	  ++i2;
 	}
       
     }
