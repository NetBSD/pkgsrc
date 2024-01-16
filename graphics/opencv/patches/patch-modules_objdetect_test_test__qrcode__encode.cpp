$NetBSD: patch-modules_objdetect_test_test__qrcode__encode.cpp,v 1.1 2024/01/16 19:23:05 adam Exp $

Fix compilation when forcing later C++.
https://github.com/opencv/opencv/pull/24194

--- modules/objdetect/test/test_qrcode_encode.cpp.orig	2024-01-16 12:42:50.298340978 +0000
+++ modules/objdetect/test/test_qrcode_encode.cpp
@@ -264,7 +264,8 @@ TEST(Objdetect_QRCode_Encode_Decode, reg
                 int true_capacity = establishCapacity(mode, version, cur_capacity);
 
                 std::string input_info = symbol_set;
-                std::random_shuffle(input_info.begin(),input_info.end());
+                std::mt19937 rand_gen {1};
+                std::shuffle(input_info.begin(), input_info.end(), rand_gen);
                 int count = 0;
                 if((int)input_info.length() > true_capacity)
                 {
@@ -391,15 +392,8 @@ TEST(Objdetect_QRCode_Encode_Decode_Stru
         std::string symbol_set = config["symbols_set"];
 
         std::string input_info = symbol_set;
-#if defined CV_CXX11
-        // std::random_shuffle is deprecated since C++11 and removed in C++17.
-        // Use manually constructed RNG with a fixed seed and std::shuffle instead.
         std::mt19937 rand_gen {1};
         std::shuffle(input_info.begin(), input_info.end(), rand_gen);
-#else
-        SeededRandFunctor<1> rand_gen;
-        std::random_shuffle(input_info.begin(), input_info.end(), rand_gen);
-#endif
         for (int j = min_stuctures_num; j < max_stuctures_num; j++)
         {
             QRCodeEncoder::Params params;
