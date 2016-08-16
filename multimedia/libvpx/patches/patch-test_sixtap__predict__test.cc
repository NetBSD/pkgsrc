$NetBSD: patch-test_sixtap__predict__test.cc,v 1.3 2016/08/16 23:53:25 ryoon Exp $

--- test/sixtap_predict_test.cc.orig	2016-07-21 01:15:41.000000000 +0000
+++ test/sixtap_predict_test.cc
@@ -32,7 +32,11 @@ typedef void (*SixtapPredictFunc)(uint8_
                                   uint8_t *dst_ptr,
                                   int dst_pitch);
 
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SixtapPredictFunc> SixtapPredictParam;
+#else
 typedef std::tr1::tuple<int, int, SixtapPredictFunc> SixtapPredictParam;
+#endif
 
 class SixtapPredictTest
     : public ::testing::TestWithParam<SixtapPredictParam> {
@@ -184,7 +188,11 @@ TEST_P(SixtapPredictTest, TestWithRandom
   }
 }
 
+#if __cplusplus >= 201103L
+using std::make_tuple;
+#else
 using std::tr1::make_tuple;
+#endif
 
 INSTANTIATE_TEST_CASE_P(
     C, SixtapPredictTest, ::testing::Values(
