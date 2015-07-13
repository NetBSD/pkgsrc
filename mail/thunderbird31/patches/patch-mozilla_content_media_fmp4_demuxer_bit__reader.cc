$NetBSD: patch-mozilla_content_media_fmp4_demuxer_bit__reader.cc,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/content/media/fmp4/demuxer/bit_reader.cc.orig	2014-07-18 00:05:12.000000000 +0000
+++ mozilla/content/media/fmp4/demuxer/bit_reader.cc
@@ -9,7 +9,7 @@ namespace mp4_demuxer {
 
 BitReader::BitReader(const uint8_t* data, off_t size)
     : data_(data), bytes_left_(size), num_remaining_bits_in_curr_byte_(0) {
-  DCHECK(data_ != nullptr && bytes_left_ > 0);
+  DCHECK(data_ != 0 && bytes_left_ > 0);
 
   UpdateCurrByte();
 }
