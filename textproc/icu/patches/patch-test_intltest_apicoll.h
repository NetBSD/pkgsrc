$NetBSD: patch-test_intltest_apicoll.h,v 1.1 2016/12/04 04:11:33 ryoon Exp $

--- test/intltest/apicoll.h.orig	2016-06-15 18:58:17.000000000 +0000
+++ test/intltest/apicoll.h
@@ -35,6 +35,7 @@ public:
      * - displayable name in the desired locale
      */
     void TestProperty(/* char* par */);
+    void TestKeywordValues();
 
     /**
     * This tests the RuleBasedCollator
