$NetBSD: patch-libtransmission_completion.cc,v 1.1 2023/02/20 17:01:51 abs Exp $

patch to fix "assertion failed leftUntilDone <= sizeWhenDone"
https://github.com/transmission/transmission/pull/4879/commits/57ff8bda34e7d752b76b750b699932500664198d

file 1/2

--- libtransmission/completion.cc.orig	2023-01-30 05:23:05.000000000 +0000
+++ libtransmission/completion.cc
@@ -156,13 +156,28 @@ void tr_completion::addPiece(tr_piece_in
     }
 }
 
-void tr_completion::removePiece(tr_piece_index_t piece)
+void tr_completion::removeBlock(tr_block_index_t block)
 {
-    auto const [begin, end] = block_info_->blockSpanForPiece(piece);
-    size_now_ -= countHasBytesInPiece(piece);
+    if (!hasBlock(block))
+    {
+        return; // already didn't have it
+    }
+
+    blocks_.unset(block);
+    size_now_ -= block_info_->blockSize(block);
+
     size_when_done_.reset();
     has_valid_.reset();
-    blocks_.unsetSpan(begin, end);
+}
+
+void tr_completion::removePiece(tr_piece_index_t piece)
+{
+    auto const [begin, end] = block_info_->blockSpanForPiece(piece);
+
+    for (auto block = begin; block < end; ++block)
+    {
+        removeBlock(block);
+    }
 }
 
 uint64_t tr_completion::countHasBytesInSpan(tr_byte_span_t span) const
