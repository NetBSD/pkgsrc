$NetBSD: patch-test_sad__test.cc,v 1.2 2014/01/02 15:18:01 ryoon Exp $

--- test/sad_test.cc.orig	2013-11-18 22:18:52.000000000 +0000
+++ test/sad_test.cc
@@ -296,7 +296,11 @@ TEST_P(SADTest, MaxSAD) {
   CheckSad(128);
 }
 
+#if __cplusplus >= 201103L
+using std::make_tuple;
+#else
 using std::tr1::make_tuple;
+#endif
 
 #if CONFIG_VP8_ENCODER
 const sad_m_by_n_fn_t sad_16x16_c = vp8_sad16x16_c;
