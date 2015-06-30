$NetBSD: patch-test_sixtap__predict__test.cc,v 1.2 2015/06/30 09:53:17 ryoon Exp $

--- test/sixtap_predict_test.cc.orig	2015-04-03 18:49:19.000000000 +0000
+++ test/sixtap_predict_test.cc
@@ -30,7 +30,11 @@ typedef void (*SixtapPredictFunc)(uint8_
                                   uint8_t *dst_ptr,
                                   int dst_pitch);
 
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SixtapPredictFunc> SixtapPredictParam;
+#else
 typedef std::tr1::tuple<int, int, SixtapPredictFunc> SixtapPredictParam;
+#endif
 
 class SixtapPredictTest
     : public ::testing::TestWithParam<SixtapPredictParam> {
@@ -182,7 +186,11 @@ TEST_P(SixtapPredictTest, TestWithRandom
   }
 }
 
+#if __cplusplus >= 201103L
+using std::make_tuple;
+#else
 using std::tr1::make_tuple;
+#endif
 
 const SixtapPredictFunc sixtap_16x16_c = vp8_sixtap_predict16x16_c;
 const SixtapPredictFunc sixtap_8x8_c = vp8_sixtap_predict8x8_c;
