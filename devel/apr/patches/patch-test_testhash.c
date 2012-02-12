$NetBSD: patch-test_testhash.c,v 1.1.2.2 2012/02/12 01:36:32 sbd Exp $

http://svn.apache.org/viewvc/apr/apr/branches/1.4.x/test/testhash.c
revision 1237547:                    
Randomise hashes by providing a seed (initial hash value).

--- test/testhash.c.orig	2007-11-01 23:01:06.000000000 +0000
+++ test/testhash.c
@@ -437,6 +437,79 @@ static void overlay_same(abts_case *tc, 
     ABTS_STR_EQUAL(tc, "#entries 5\n", StrArray[5]);
 }
 
+static void overlay_fetch(abts_case *tc, void *data)
+{
+    apr_hash_t *base = NULL;
+    apr_hash_t *overlay = NULL;
+    apr_hash_t *result = NULL;
+    int count;
+
+    base = apr_hash_make(p);
+    overlay = apr_hash_make(p);
+    ABTS_PTR_NOTNULL(tc, base);
+    ABTS_PTR_NOTNULL(tc, overlay);
+
+    apr_hash_set(base, "base1", APR_HASH_KEY_STRING, "value1");
+    apr_hash_set(base, "base2", APR_HASH_KEY_STRING, "value2");
+    apr_hash_set(base, "base3", APR_HASH_KEY_STRING, "value3");
+    apr_hash_set(base, "base4", APR_HASH_KEY_STRING, "value4");
+    apr_hash_set(base, "base5", APR_HASH_KEY_STRING, "value5");
+
+    apr_hash_set(overlay, "overlay1", APR_HASH_KEY_STRING, "value1");
+    apr_hash_set(overlay, "overlay2", APR_HASH_KEY_STRING, "value2");
+    apr_hash_set(overlay, "overlay3", APR_HASH_KEY_STRING, "value3");
+    apr_hash_set(overlay, "overlay4", APR_HASH_KEY_STRING, "value4");
+    apr_hash_set(overlay, "overlay5", APR_HASH_KEY_STRING, "value5");
+
+    result = apr_hash_overlay(p, overlay, base);
+
+    count = apr_hash_count(result);
+    ABTS_INT_EQUAL(tc, 10, count);
+
+    ABTS_STR_EQUAL(tc, "value1",
+                       apr_hash_get(result, "base1", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value2",
+                       apr_hash_get(result, "base2", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value3",
+                       apr_hash_get(result, "base3", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value4",
+                       apr_hash_get(result, "base4", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value5",
+                       apr_hash_get(result, "base5", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value1",
+                       apr_hash_get(result, "overlay1", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value2",
+                       apr_hash_get(result, "overlay2", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value3",
+                       apr_hash_get(result, "overlay3", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value4",
+                       apr_hash_get(result, "overlay4", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value5",
+                       apr_hash_get(result, "overlay5", APR_HASH_KEY_STRING));
+
+    ABTS_STR_EQUAL(tc, "value1",
+                       apr_hash_get(base, "base1", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value2",
+                       apr_hash_get(base, "base2", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value3",
+                       apr_hash_get(base, "base3", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value4",
+                       apr_hash_get(base, "base4", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value5",
+                       apr_hash_get(base, "base5", APR_HASH_KEY_STRING));
+
+    ABTS_STR_EQUAL(tc, "value1",
+                       apr_hash_get(overlay, "overlay1", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value2",
+                       apr_hash_get(overlay, "overlay2", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value3",
+                       apr_hash_get(overlay, "overlay3", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value4",
+                       apr_hash_get(overlay, "overlay4", APR_HASH_KEY_STRING));
+    ABTS_STR_EQUAL(tc, "value5",
+                       apr_hash_get(overlay, "overlay5", APR_HASH_KEY_STRING));
+}
+
 abts_suite *testhash(abts_suite *suite)
 {
     suite = ADD_SUITE(suite)
@@ -460,6 +533,7 @@ abts_suite *testhash(abts_suite *suite)
     abts_run_test(suite, overlay_empty, NULL);
     abts_run_test(suite, overlay_2unique, NULL);
     abts_run_test(suite, overlay_same, NULL);
+    abts_run_test(suite, overlay_fetch, NULL);
 
     return suite;
 }
