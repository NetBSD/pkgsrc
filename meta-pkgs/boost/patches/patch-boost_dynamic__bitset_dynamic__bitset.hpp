$NetBSD: patch-boost_dynamic__bitset_dynamic__bitset.hpp,v 1.1 2014/03/31 08:36:51 wiz Exp $

Fix "implicit conversion changes signedness" warnings.
https://svn.boost.org/trac/boost/ticket/9725

--- boost/dynamic_bitset/dynamic_bitset.hpp.orig	2013-09-21 20:17:00.000000000 +0000
+++ boost/dynamic_bitset/dynamic_bitset.hpp
@@ -1230,7 +1230,7 @@ dynamic_bitset<Block, Allocator>::m_do_f
     if (i >= num_blocks())
         return npos; // not found
 
-    return i * bits_per_block + boost::lowest_bit(m_bits[i]);
+    return i * bits_per_block + static_cast<size_type>(boost::lowest_bit(m_bits[i]));
 
 }
 
@@ -1261,7 +1261,7 @@ dynamic_bitset<Block, Allocator>::find_n
     const Block fore = m_bits[blk] & ( ~Block(0) << ind );
 
     return fore?
-        blk * bits_per_block + lowest_bit(fore)
+        blk * bits_per_block + static_cast<size_type>(lowest_bit(fore))
         :
         m_do_find_from(blk + 1);
 
@@ -1694,7 +1694,7 @@ inline typename dynamic_bitset<Block, Al
 dynamic_bitset<Block, Allocator>::calc_num_blocks(size_type num_bits)
 {
     return num_bits / bits_per_block
-           + static_cast<int>( num_bits % bits_per_block != 0 );
+           + static_cast<size_type>( num_bits % bits_per_block != 0 );
 }
 
 // gives a reference to the highest block
