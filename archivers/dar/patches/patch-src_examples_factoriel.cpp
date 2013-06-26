$NetBSD: patch-src_examples_factoriel.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/examples/factoriel.cpp.orig	2013-06-20 19:26:28.000000000 +0000
+++ src/examples/factoriel.cpp
@@ -85,7 +85,7 @@ static int little_main(user_interaction 
 	exit(1);
 
     string s = argv[1];
-    deci f = s;
+    libdar::deci f = s;
     infinint max = f.computer();
     infinint i = 2;
     infinint p = 1;
@@ -97,7 +97,7 @@ static int little_main(user_interaction 
     }
 
     ui.warning("calcul finished, now computing the decimal representation ... ");
-    f = deci(p);
+    f = libdar::deci(p);
     ui.warning(f.human());
     if(argc == 3)
     {
@@ -112,7 +112,7 @@ static int little_main(user_interaction 
 	    p.dump(fic);
 	    fic.skip(0);
 	    cp = infinint(fic);
-	    ui.warning(string("read from file: ") + deci(cp).human());
+	    ui.warning(string("read from file: ") + libdar::deci(cp).human());
 	}
     }
 
