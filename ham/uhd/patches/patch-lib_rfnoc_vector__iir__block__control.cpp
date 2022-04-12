$NetBSD: patch-lib_rfnoc_vector__iir__block__control.cpp,v 1.1 2022/04/12 20:10:46 tnn Exp $

Avoid ambiguous call to pow on SunOS.

--- lib/rfnoc/vector_iir_block_control.cpp.orig	2021-12-14 18:37:20.000000000 +0000
+++ lib/rfnoc/vector_iir_block_control.cpp
@@ -109,7 +109,7 @@ private:
                     throw uhd::value_error("Alpha value must be in [0.0, 1.0]");
                 }
                 _vector_iir_reg_iface.poke32(
-                    REG_ALPHA_OFFSET, uint32_t(alpha * pow(2, 31)), chan);
+                    REG_ALPHA_OFFSET, uint32_t(alpha * pow((double)2, (double)31)), chan);
             });
             register_property(&_prop_beta.back(), [this, chan]() {
                 double beta = _prop_beta.at(chan).get();
@@ -117,7 +117,7 @@ private:
                     throw uhd::value_error("Beta value must be in [0.0, 1.0]");
                 }
                 _vector_iir_reg_iface.poke32(
-                    REG_BETA_OFFSET, uint32_t(beta * pow(2, 31)), chan);
+                    REG_BETA_OFFSET, uint32_t(beta * pow((double)2, (double)31)), chan);
             });
             register_property(&_prop_delay.back(), [this, chan, max_delay]() {
                 int length = _prop_delay.at(chan).get();
