$NetBSD: patch-gr-blocks_include_gnuradio_blocks_blockinterleaving.h,v 1.1 2022/10/09 07:56:51 adam Exp $

Fix building.

--- gr-blocks/include/gnuradio/blocks/blockinterleaving.h.orig	2022-09-16 15:51:17.000000000 +0000
+++ gr-blocks/include/gnuradio/blocks/blockinterleaving.h
@@ -11,6 +11,8 @@
 #ifndef INCLUDED_GR_BLOCKS_BLOCKINTERLEAVING_H
 #define INCLUDED_GR_BLOCKS_BLOCKINTERLEAVING_H
 
+#include <cstddef>
+#include <vector>
 #include <gnuradio/blocks/api.h>
 
 
