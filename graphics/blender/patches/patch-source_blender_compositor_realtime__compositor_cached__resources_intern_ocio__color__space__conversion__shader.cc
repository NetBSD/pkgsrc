$NetBSD: patch-source_blender_compositor_realtime__compositor_cached__resources_intern_ocio__color__space__conversion__shader.cc,v 1.1 2026/01/05 18:01:07 adam Exp $

Fix build with opencolorio 2.5.

--- source/blender/compositor/realtime_compositor/cached_resources/intern/ocio_color_space_conversion_shader.cc.orig	2026-01-05 17:24:10.326855833 +0000
+++ source/blender/compositor/realtime_compositor/cached_resources/intern/ocio_color_space_conversion_shader.cc
@@ -168,7 +168,12 @@ class GPUShaderCreator : public OCIO::Gp
 
   bool addUniform(const char *name,
                   const SizeGetter &get_size,
-                  const VectorFloatGetter &get_vector_float) override
+                  const VectorFloatGetter &get_vector_float
+#  if OCIO_VERSION_HEX >= 0x02050000
+                  ,
+                  const unsigned /*maxSize*/
+#  endif
+                  ) override
   {
     /* Check if a resource exists with the same name and assert if it is the case, returning false
      * indicates failure to add the uniform for the shader creator. */
@@ -190,7 +195,12 @@ class GPUShaderCreator : public OCIO::Gp
 
   bool addUniform(const char *name,
                   const SizeGetter &get_size,
-                  const VectorIntGetter &get_vector_int) override
+                  const VectorIntGetter &get_vector_int
+#  if OCIO_VERSION_HEX >= 0x02050000
+                  ,
+                  const unsigned /*maxSize*/
+#  endif
+                  ) override
   {
     /* Check if a resource exists with the same name and assert if it is the case, returning false
      * indicates failure to add the uniform for the shader creator. */
@@ -210,7 +220,12 @@ class GPUShaderCreator : public OCIO::Gp
     return true;
   }
 
-  void addTexture(const char *texture_name,
+#  if OCIO_VERSION_HEX >= 0x02050000
+  unsigned
+#  else
+  void
+#  endif
+  addTexture(const char *texture_name,
                   const char *sampler_name,
                   uint width,
                   uint height,
@@ -252,9 +267,17 @@ class GPUShaderCreator : public OCIO::Gp
     GPU_texture_filter_mode(texture, interpolation != OCIO::INTERP_NEAREST);
 
     textures_.add(sampler_name, texture);
+#  if OCIO_VERSION_HEX >= 0x02050000
+    return textures_.size() - 1;
+#  endif
   }
 
-  void add3DTexture(const char *texture_name,
+#  if OCIO_VERSION_HEX >= 0x02050000
+  unsigned
+#  else
+  void
+#  endif
+  add3DTexture(const char *texture_name,
                     const char *sampler_name,
                     uint size,
                     OCIO::Interpolation interpolation,
@@ -282,12 +305,18 @@ class GPUShaderCreator : public OCIO::Gp
     GPU_texture_filter_mode(texture, interpolation != OCIO::INTERP_NEAREST);
 
     textures_.add(sampler_name, texture);
+#  if OCIO_VERSION_HEX >= 0x02050000
+    return textures_.size() - 1;
+#  endif
   }
 
   /* This gets called before the finalize() method to construct the shader code. We just
    * concatenate the code except for the declarations section. That's because the ShaderCreateInfo
    * will add the declaration itself. */
   void createShaderText(const char * /*declarations*/,
+#  if OCIO_VERSION_HEX >= 0x02050000
+                        const char * /*texture_declarations*/,
+#  endif
                         const char *helper_methods,
                         const char *function_header,
                         const char *function_body,
