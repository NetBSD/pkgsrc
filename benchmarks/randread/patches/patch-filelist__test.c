$NetBSD: patch-filelist__test.c,v 1.1 2011/02/03 14:15:12 obache Exp $

* suite_free is not required by check>=0.9.0, everything will be freed when
  srunner_free is called.

--- filelist_test.c.orig	2002-09-11 05:15:40.000000000 +0000
+++ filelist_test.c
@@ -177,7 +177,6 @@ int main(void) 
     srunner_run_all (sr, CK_NORMAL); 
     num_failed = srunner_ntests_failed (sr); 
     srunner_free (sr); 
-    suite_free (s); 
 
     return num_failed;
 }
