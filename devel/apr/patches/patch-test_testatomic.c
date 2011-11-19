$NetBSD: patch-test_testatomic.c,v 1.1 2011/11/19 21:16:22 alnsn Exp $
https://issues.apache.org/bugzilla/show_bug.cgi?id=51851

--- test/testatomic.c.orig	2007-11-18 00:35:57.000000000 +0000
+++ test/testatomic.c
@@ -84,11 +84,12 @@ static void test_xchg32(abts_case *tc, v
 static void test_xchgptr(abts_case *tc, void *data)
 {
     int a;
-    volatile void *target_ptr = NULL;
+    void *ref = "little piggy";
+    volatile void *target_ptr = ref;
     void *old_ptr;
 
     old_ptr = apr_atomic_xchgptr(&target_ptr, &a);
-    ABTS_PTR_EQUAL(tc, NULL, old_ptr);
+    ABTS_PTR_EQUAL(tc, ref, old_ptr);
     ABTS_PTR_EQUAL(tc, &a, (void *) target_ptr);
 }
 
