$NetBSD: patch-tests_rfnoc__block__tests_vector__iir__block__test.cpp,v 1.1 2022/04/12 20:10:46 tnn Exp $

Avoid ambiguous call to pow on SunOS.

--- tests/rfnoc_block_tests/vector_iir_block_test.cpp.orig	2021-12-14 18:37:20.000000000 +0000
+++ tests/rfnoc_block_tests/vector_iir_block_test.cpp
@@ -94,7 +94,7 @@ struct vector_iir_block_fixture
 
     inline uint32_t calculate_alphabeta_register_value(double alphabeta) const
     {
-        return uint32_t(alphabeta * pow(2, 31));
+        return uint32_t(alphabeta * pow((double)2, (double)31));
     }
 
     inline size_t calculate_register_address(size_t offset, size_t channel) const
