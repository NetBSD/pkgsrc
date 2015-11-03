$NetBSD: patch-src_ifkp_ifkp.cxx,v 1.1 2015/11/03 19:03:27 joerg Exp $

std::complex::imag() and std::complex::real() are not lvalues.

--- src/ifkp/ifkp.cxx.orig	2015-10-25 14:22:27.000000000 +0000
+++ src/ifkp/ifkp.cxx
@@ -580,9 +580,11 @@ int ifkp::rx_process(const double *buf, 
 						&rx_stream[IFKP_SHIFT_SIZE],			// from
 						IFKP_BLOCK_SIZE*sizeof(*rx_stream));	// # bytes
 				memset(fft_data, 0, sizeof(fft_data));
-				for (int i = 0; i < IFKP_BLOCK_SIZE; i++)
-					fft_data[i].real() = fft_data[i].imag() =
-						rx_stream[i] * a_blackman[i];
+				for (int i = 0; i < IFKP_BLOCK_SIZE; i++) {
+					double r = rx_stream[i] * a_blackman[i];
+					fft_data[i].real(r);
+					fft_data[i].imag(r);
+				}
 				fft->ComplexFFT(fft_data);
 				process_tones();
 			}
