$NetBSD: patch-test_sad__test.cc,v 1.1 2013/09/13 15:00:43 joerg Exp $

--- test/sad_test.cc.orig	2013-09-12 10:19:23.000000000 +0000
+++ test/sad_test.cc
@@ -182,7 +182,11 @@ TEST_P(SADTest, MaxSAD) {
   CheckSad(128);
 }
 
+#if __cplusplus >= 201103L
+using std::make_tuple;
+#else
 using std::tr1::make_tuple;
+#endif
 
 const sad_m_by_n_fn_t sad_16x16_c = vp8_sad16x16_c;
 const sad_m_by_n_fn_t sad_8x16_c = vp8_sad8x16_c;
