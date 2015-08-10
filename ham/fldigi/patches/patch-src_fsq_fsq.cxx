$NetBSD: patch-src_fsq_fsq.cxx,v 1.1 2015/08/10 19:26:43 joerg Exp $

--- src/fsq/fsq.cxx.orig	2015-07-21 14:54:32.000000000 +0000
+++ src/fsq/fsq.cxx
@@ -1197,9 +1197,12 @@ int fsq::rx_process(const double *buf, i
 						&rx_stream[SHIFT_SIZE],				// from
 						BLOCK_SIZE*sizeof(*rx_stream));	// # bytes
 				memset(fft_data, 0, sizeof(fft_data));
-				for (int i = 0; i < BLOCK_SIZE; i++)
-					fft_data[i].real() = fft_data[i].imag() =
-						rx_stream[i] * a_blackman[i];
+				for (int i = 0; i < BLOCK_SIZE; i++) {
+					double r = rx_stream[i] * a_blackman[i];
+					fft_data[i].real(r);
+					fft_data[i].imag(r);
+				}
+						
 				fft->ComplexFFT(fft_data);
 				process_tones();
 			}
