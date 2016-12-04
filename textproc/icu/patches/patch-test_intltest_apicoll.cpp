$NetBSD: patch-test_intltest_apicoll.cpp,v 1.1 2016/12/04 04:11:33 ryoon Exp $

--- test/intltest/apicoll.cpp.orig	2016-09-20 04:30:06.000000000 +0000
+++ test/intltest/apicoll.cpp
@@ -81,17 +81,10 @@ CollationAPITest::TestProperty(/* char* 
     logln("Test ctors : ");
     col = Collator::createInstance(Locale::getEnglish(), success);
     if (U_FAILURE(success)){
-        errcheckln(success, "Default Collator creation failed. - %s", u_errorName(success));
+        errcheckln(success, "English Collator creation failed. - %s", u_errorName(success));
         return;
     }
 
-    StringEnumeration* kwEnum = col->getKeywordValuesForLocale("", Locale::getEnglish(),true,success);
-    if (U_FAILURE(success)){
-        errcheckln(success, "Get Keyword Values for Locale failed. - %s", u_errorName(success));
-        return;
-    }
-    delete kwEnum;
-
     col->getVersion(versionArray);
     // Check for a version greater than some value rather than equality
     // so that we need not update the expected version each time.
@@ -231,6 +224,29 @@ CollationAPITest::TestProperty(/* char* 
     delete junk;
 }
 
+void CollationAPITest::TestKeywordValues() {
+    IcuTestErrorCode errorCode(*this, "TestKeywordValues");
+    LocalPointer<Collator> col(Collator::createInstance(Locale::getEnglish(), errorCode));
+    if (errorCode.logIfFailureAndReset("English Collator creation failed")) {
+        return;
+    }
+
+    LocalPointer<StringEnumeration> kwEnum(
+        col->getKeywordValuesForLocale("collation", Locale::getEnglish(), TRUE, errorCode));
+    if (errorCode.logIfFailureAndReset("Get Keyword Values for English Collator failed")) {
+        return;
+    }
+    assertTrue("expect at least one collation tailoring for English", kwEnum->count(errorCode) > 0);
+    const char *kw;
+    UBool hasStandard = FALSE;
+    while ((kw = kwEnum->next(NULL, errorCode)) != NULL) {
+        if (strcmp(kw, "standard") == 0) {
+            hasStandard = TRUE;
+        }
+    }
+    assertTrue("expect at least the 'standard' collation tailoring for English", hasStandard);
+}
+
 void 
 CollationAPITest::TestRuleBasedColl()
 {
@@ -2466,6 +2482,7 @@ void CollationAPITest::runIndexedTest( i
     if (exec) logln("TestSuite CollationAPITest: ");
     TESTCASE_AUTO_BEGIN;
     TESTCASE_AUTO(TestProperty);
+    TESTCASE_AUTO(TestKeywordValues);
     TESTCASE_AUTO(TestOperators);
     TESTCASE_AUTO(TestDuplicate);
     TESTCASE_AUTO(TestCompare);
