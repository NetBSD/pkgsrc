$NetBSD: patch-lib_rfnoc_dma__fifo__block__ctrl__impl.cpp,v 1.1 2020/05/14 19:21:04 joerg Exp $

--- lib/rfnoc/dma_fifo_block_ctrl_impl.cpp.orig	2020-05-09 17:48:24.246248533 +0000
+++ lib/rfnoc/dma_fifo_block_ctrl_impl.cpp
@@ -58,7 +58,7 @@ public:
             _tree->access<int>(get_arg_path("base_addr/value", i))
                 .add_coerced_subscriber(boost::bind(&dma_fifo_block_ctrl_impl::resize,
                     this,
-                    _1,
+                    boost::placeholders::_1,
                     boost::ref(_perifs[i].depth),
                     i))
                 .set(_perifs[i].base_addr);
@@ -66,7 +66,7 @@ public:
                 .add_coerced_subscriber(boost::bind(&dma_fifo_block_ctrl_impl::resize,
                     this,
                     boost::ref(_perifs[i].base_addr),
-                    _1,
+                    boost::placeholders::_1,
                     i))
                 .set(_perifs[i].depth);
         }
