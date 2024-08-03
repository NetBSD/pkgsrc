$NetBSD: patch-app_render_renderer.cpp,v 1.1 2024/08/03 11:13:27 nia Exp $

From: Tobias Mayer <tobim@fastmail.fm>
Date: Tue, 24 Oct 2023 18:48:35 +0200
Subject: [PATCH] Add OpenColorIO 2.3 compatibility

The signature of the `getTexture` function changed and the calling
code needs to be adapted.

Signed-off-by: Tobias Mayer <tobim@fastmail.fm>

--- app/render/renderer.cpp.orig	2023-09-24 11:40:23.000000000 +0000
+++ app/render/renderer.cpp
@@ -240,9 +240,17 @@ bool Renderer::GetColorContext(const Col
       const char* sampler_name = nullptr;
       unsigned int width = 0, height = 0;
       OCIO::GpuShaderDesc::TextureType channel = OCIO::GpuShaderDesc::TEXTURE_RGB_CHANNEL;
+#if OCIO_VERSION_HEX >= 0x02030000
+      OCIO::GpuShaderDesc::TextureDimensions dimensions = OCIO::GpuShaderDesc::TEXTURE_2D;
+#endif
       OCIO::Interpolation interpolation = OCIO::INTERP_LINEAR;
 
-      shader_desc->getTexture(i, tex_name, sampler_name, width, height, channel, interpolation);
+      shader_desc->getTexture(i, tex_name, sampler_name, width, height, channel,
+#if OCIO_VERSION_HEX >= 0x02030000
+                              // OCIO::GpuShaderDesc::TextureDimensions
+                              dimensions,
+#endif
+                              interpolation);
 
       if (!tex_name || !*tex_name
           || !sampler_name || !*sampler_name
