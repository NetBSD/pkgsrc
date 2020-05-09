$NetBSD: patch-gr-blocks_lib_wavfile.cc,v 1.1 2020/05/09 15:17:51 joerg Exp $

--- gr-blocks/lib/wavfile.cc.orig	2020-05-09 00:06:11.248216593 +0000
+++ gr-blocks/lib/wavfile.cc
@@ -27,7 +27,7 @@
 #include <gnuradio/blocks/wavfile.h>
 #include <cstring>
 #include <stdint.h>
-#include <boost/detail/endian.hpp> //BOOST_BIG_ENDIAN
+#include <boost/predef/other/endian.h>
 
 namespace gr {
   namespace blocks {
@@ -35,7 +35,7 @@ namespace gr {
 
     // Basically, this is the opposite of htonx() and ntohx()
     // Define host to/from worknet (little endian) short and long
-#ifdef BOOST_BIG_ENDIAN
+#if BOOST_ENDIAN_BIG_BYTE
 
     static inline uint16_t __gri_wav_bs16(uint16_t x)
     {
@@ -52,7 +52,7 @@ namespace gr {
     #define htows(x) __gri_wav_bs16(x)
     #define wtohs(x) __gri_wav_bs16(x)
 
-#else
+#elif BOOST_ENDIAN_LITTLE_BYTE
 
     #define htowl(x) uint32_t(x)
     #define wtohl(x) uint32_t(x)
