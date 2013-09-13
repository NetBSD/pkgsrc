$NetBSD: patch-test_sixtap__predict__test.cc,v 1.1 2013/09/13 15:00:43 joerg Exp $

--- test/sixtap_predict_test.cc.orig	2013-09-12 10:12:12.000000000 +0000
+++ test/sixtap_predict_test.cc
@@ -175,7 +175,11 @@ TEST_P(SixtapPredictTest, TestWithRandom
   }
 }
 
+#if __cplusplus >= 201103L
+using std::make_tuple;
+#else
 using std::tr1::make_tuple;
+#endif
 
 const sixtap_predict_fn_t sixtap_16x16_c = vp8_sixtap_predict16x16_c;
 const sixtap_predict_fn_t sixtap_8x8_c = vp8_sixtap_predict8x8_c;
