$NetBSD: patch-lib_CL_pocl__llvm__metadata.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/CL/pocl_llvm_metadata.cc.orig	2024-06-18 12:15:45.000000000 +0000
+++ lib/CL/pocl_llvm_metadata.cc
@@ -52,10 +52,10 @@ using namespace llvm;
 static inline bool is_image_type(const llvm::Type &t) {
   if (t.isPointerTy() && t.getPointerElementType()->isStructTy()) {
     llvm::StringRef name = t.getPointerElementType()->getStructName();
-    if (name.startswith("opencl.image2d_") ||
-        name.startswith("opencl.image3d_") ||
-        name.startswith("opencl.image1d_") ||
-        name.startswith("struct._pocl_image"))
+    if (name.starts_with("opencl.image2d_") ||
+        name.starts_with("opencl.image3d_") ||
+        name.starts_with("opencl.image1d_") ||
+        name.starts_with("struct._pocl_image"))
       return true;
   }
   return false;
@@ -64,7 +64,7 @@ static inline bool is_image_type(const l
 static inline bool is_sampler_type(const llvm::Type &t) {
   if (t.isPointerTy() && t.getPointerElementType()->isStructTy()) {
     llvm::StringRef name = t.getPointerElementType()->getStructName();
-    if (name.startswith("opencl.sampler_t"))
+    if (name.starts_with("opencl.sampler_t"))
       return true;
   }
   return false;
@@ -79,8 +79,8 @@ static inline bool is_image_type(struct
     llvm::StringRef name(ArgInfo.type_name);
     if ((has_arg_meta & POCL_HAS_KERNEL_ARG_ACCESS_QUALIFIER) &&
         (ArgInfo.access_qualifier != CL_KERNEL_ARG_ACCESS_NONE)) {
-      if (name.startswith("image2d_") || name.startswith("image3d_") ||
-          name.startswith("image1d_") || name.startswith("_pocl_image"))
+      if (name.starts_with("image2d_") || name.starts_with("image3d_") ||
+          name.starts_with("image1d_") || name.starts_with("_pocl_image"))
         return true;
     }
   }
@@ -91,10 +91,7 @@ static inline bool is_sampler_type(struc
                                    cl_bitfield has_arg_meta) {
   assert(has_arg_meta & POCL_HAS_KERNEL_ARG_TYPE_NAME);
   llvm::StringRef name(ArgInfo.type_name);
-  if (name.equals("sampler_t"))
-    return true;
-  else
-    return false;
+  return name == "sampler_t";
 }
 #endif
 
