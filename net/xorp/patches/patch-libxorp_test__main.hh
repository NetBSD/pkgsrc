$NetBSD: patch-libxorp_test__main.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- libxorp/test_main.hh.orig	2012-07-03 16:37:33.000000000 +0000
+++ libxorp/test_main.hh
@@ -292,13 +292,9 @@ public:
 //  	if (_verbose)
 	    cout << "Running: " << test_name << endl;
 	TestInfo info(test_name, _verbose, _verbose_level, cout);
-	switch (cb->dispatch(info)) {
-	case true:
-	    break;
-	case false:
+	if (!cb->dispatch(info)) {
 	   _exit_status = false;
 	   cerr << "Failed: " << test_name << endl;
-	   break;
 	}
     }
 
