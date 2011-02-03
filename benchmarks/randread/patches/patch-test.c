$NetBSD: patch-test.c,v 1.1 2011/02/03 14:15:12 obache Exp $

* suite_free is not required by check>=0.9.0, everything will be freed when
  srunner_free is called.

--- test.c.orig	2002-07-11 08:23:49.000000000 +0000
+++ test.c
@@ -31,7 +31,6 @@ int main(void) 
     srunner_run_all (sr, CK_NORMAL); 
     num_failed = srunner_ntests_failed (sr); 
     srunner_free (sr); 
-    suite_free (s); 
 
     return num_failed;
 }
