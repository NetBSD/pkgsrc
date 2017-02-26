$NetBSD: patch-snappy__unittest.cc,v 1.1 2017/02/26 08:41:17 adam Exp $

Depending on the definition of LZF_STATE_ARG, lzf can grow an extra arg.
Accommodate.

--- snappy_unittest.cc.orig	1980-01-01 08:00:00.000000000 +0000
+++ snappy_unittest.cc
@@ -219,10 +219,17 @@ static bool Compress(const char* input, 
 
 #ifdef LZF_VERSION
     case LIBLZF: {
+#  ifdef LZF_STATE_ARG
+      LZF_STATE htab;
+#  endif
       int destlen = lzf_compress(input,
                                  input_size,
                                  string_as_array(compressed),
-                                 input_size);
+                                 input_size
+#  ifdef LZF_STATE_ARG
+				 , htab
+#  endif
+				 );
       if (destlen == 0) {
         // lzf *can* cause lots of blowup when compressing, so they
         // recommend to limit outsize to insize, and just not compress
