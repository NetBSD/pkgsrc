$NetBSD: patch-libtransmission_completion.h,v 1.1 2023/02/20 17:01:51 abs Exp $

patch to fix "assertion failed leftUntilDone <= sizeWhenDone"
https://github.com/transmission/transmission/pull/4879/commits/57ff8bda34e7d752b76b750b699932500664198d

file 2/2

--- libtransmission/completion.h.orig	2023-01-30 05:23:05.000000000 +0000
+++ libtransmission/completion.h
@@ -172,6 +172,8 @@ private:
         return countHasBytesInSpan(block_info_->byteSpanForPiece(piece));
     }
 
+    void removeBlock(tr_block_index_t block);
+
     torrent_view const* tor_;
     tr_block_info const* block_info_;
 
