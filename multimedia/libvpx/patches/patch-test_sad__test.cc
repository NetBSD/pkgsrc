$NetBSD: patch-test_sad__test.cc,v 1.4 2015/11/18 14:09:25 ryoon Exp $

--- test/sad_test.cc.orig	2015-11-09 22:12:38.000000000 +0000
+++ test/sad_test.cc
@@ -29,21 +29,33 @@ typedef unsigned int (*SadMxNFunc)(const
                                    int src_stride,
                                    const uint8_t *ref_ptr,
                                    int ref_stride);
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SadMxNFunc, int> SadMxNParam;
+#else
 typedef std::tr1::tuple<int, int, SadMxNFunc, int> SadMxNParam;
+#endif
 
 typedef uint32_t (*SadMxNAvgFunc)(const uint8_t *src_ptr,
                                   int src_stride,
                                   const uint8_t *ref_ptr,
                                   int ref_stride,
                                   const uint8_t *second_pred);
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SadMxNAvgFunc, int> SadMxNAvgParam;
+#else
 typedef std::tr1::tuple<int, int, SadMxNAvgFunc, int> SadMxNAvgParam;
+#endif
 
 typedef void (*SadMxNx4Func)(const uint8_t *src_ptr,
                              int src_stride,
                              const uint8_t *const ref_ptr[],
                              int ref_stride,
                              uint32_t *sad_array);
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SadMxNx4Func, int> SadMxNx4Param;
+#else
 typedef std::tr1::tuple<int, int, SadMxNx4Func, int> SadMxNx4Param;
+#endif
 
 using libvpx_test::ACMRandom;
 
@@ -480,7 +492,11 @@ TEST_P(SADx4Test, SrcAlignedByWidth) {
   source_data_ = tmp_source_data;
 }
 
+#if __cplusplus >= 201103L
+using std::make_tuple;
+#else
 using std::tr1::make_tuple;
+#endif
 
 //------------------------------------------------------------------------------
 // C functions
