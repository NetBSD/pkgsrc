$NetBSD: patch-test_sad__test.cc,v 1.3 2015/06/30 09:53:17 ryoon Exp $

--- test/sad_test.cc.orig	2015-04-03 18:49:19.000000000 +0000
+++ test/sad_test.cc
@@ -36,28 +36,44 @@ typedef unsigned int (*SadMxNFunc)(const
                                    const unsigned char *reference_ptr,
                                    int reference_stride,
                                    unsigned int max_sad);
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SadMxNFunc, int> SadMxNParam;
+#else
 typedef std::tr1::tuple<int, int, SadMxNFunc, int> SadMxNParam;
 #endif
+#endif
 #if CONFIG_VP9_ENCODER
 typedef unsigned int (*SadMxNVp9Func)(const unsigned char *source_ptr,
                                       int source_stride,
                                       const unsigned char *reference_ptr,
                                       int reference_stride);
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SadMxNVp9Func, int> SadMxNVp9Param;
+#else
 typedef std::tr1::tuple<int, int, SadMxNVp9Func, int> SadMxNVp9Param;
+#endif
 typedef uint32_t (*SadMxNAvgVp9Func)(const uint8_t *source_ptr,
                                      int source_stride,
                                      const uint8_t *reference_ptr,
                                      int reference_stride,
                                      const uint8_t *second_pred);
+#if __cplusplus >= 201103L
+typedef std::tuple<int, int, SadMxNAvgVp9Func, int> SadMxNAvgVp9Param;
+#else
 typedef std::tr1::tuple<int, int, SadMxNAvgVp9Func, int> SadMxNAvgVp9Param;
 #endif
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
 
@@ -637,7 +653,11 @@ TEST_P(SADx4Test, SrcAlignedByWidth) {
   source_data_ = tmp_source_data;
 }
 
+#if __cplusplus >= 201103L
+using std::make_tuple;
+#else
 using std::tr1::make_tuple;
+#endif
 
 //------------------------------------------------------------------------------
 // C functions
