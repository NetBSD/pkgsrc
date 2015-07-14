$NetBSD: patch-3rdparty_bgfx_src_renderer__null.cpp,v 1.1 2015/07/14 20:14:49 wiz Exp $

Fix build.
https://github.com/bkaradzic/bgfx/commit/e1a564ca720ae66298b61928e6ef0e9d1ee40d30#diff-d51370988baf340d4de0bc2861591415

--- 3rdparty/bgfx/src/renderer_null.cpp.orig	2015-06-24 09:53:24.000000000 +0000
+++ 3rdparty/bgfx/src/renderer_null.cpp
@@ -33,7 +33,7 @@ namespace bgfx { namespace noop
 		{
 		}
 
-		void createIndexBuffer(IndexBufferHandle /*_handle*/, Memory* /*_mem*/, uint8_t /*_flags*/) BX_OVERRIDE
+		void createIndexBuffer(IndexBufferHandle /*_handle*/, Memory* /*_mem*/, uint16_t /*_flags*/) BX_OVERRIDE
 		{
 		}
 
@@ -49,7 +49,7 @@ namespace bgfx { namespace noop
 		{
 		}
 
-		void createVertexBuffer(VertexBufferHandle /*_handle*/, Memory* /*_mem*/, VertexDeclHandle /*_declHandle*/, uint8_t /*_flags*/) BX_OVERRIDE
+		void createVertexBuffer(VertexBufferHandle /*_handle*/, Memory* /*_mem*/, VertexDeclHandle /*_declHandle*/, uint16_t /*_flags*/) BX_OVERRIDE
 		{
 		}
 
@@ -57,7 +57,7 @@ namespace bgfx { namespace noop
 		{
 		}
 
-		void createDynamicIndexBuffer(IndexBufferHandle /*_handle*/, uint32_t /*_size*/, uint8_t /*_flags*/) BX_OVERRIDE
+		void createDynamicIndexBuffer(IndexBufferHandle /*_handle*/, uint32_t /*_size*/, uint16_t /*_flags*/) BX_OVERRIDE
 		{
 		}
 
@@ -69,7 +69,7 @@ namespace bgfx { namespace noop
 		{
 		}
 
-		void createDynamicVertexBuffer(VertexBufferHandle /*_handle*/, uint32_t /*_size*/, uint8_t /*_flags*/) BX_OVERRIDE
+		void createDynamicVertexBuffer(VertexBufferHandle /*_handle*/, uint32_t /*_size*/, uint16_t /*_flags*/) BX_OVERRIDE
 		{
 		}
 
