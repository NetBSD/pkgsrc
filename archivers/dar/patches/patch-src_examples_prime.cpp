$NetBSD: patch-src_examples_prime.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/examples/prime.cpp.orig	2013-06-20 19:27:04.000000000 +0000
+++ src/examples/prime.cpp
@@ -58,7 +58,7 @@ int little_main(user_interaction & ui, S
         exit(1);
     }
 
-    deci x = string(argv[1]);
+    libdar::deci x = string(argv[1]);
     cout << "converting string to infinint... " << endl;
     infinint num = x.computer();
     cout << "checking whether the number is a prime factor... " << endl;
