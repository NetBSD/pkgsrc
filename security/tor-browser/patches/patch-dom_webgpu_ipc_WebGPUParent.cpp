$NetBSD: patch-dom_webgpu_ipc_WebGPUParent.cpp,v 1.1.2.2 2021/01/04 17:22:33 bsiegert Exp $

* Fix build with devel/cbindgen-0.16.0.
  From https://bugzilla.mozilla.org/show_bug.cgi?id=1684180

--- dom/webgpu/ipc/WebGPUParent.cpp.orig	2020-12-08 01:14:39.000000000 +0000
+++ dom/webgpu/ipc/WebGPUParent.cpp
@@ -423,17 +423,15 @@ ipc::IPCResult WebGPUParent::RecvDeviceC
     switch (entry.mType) {
       case SerialBindGroupEntryType::Buffer:
         bgb.resource.tag = ffi::WGPUBindingResource_Buffer;
-        bgb.resource.buffer._0.buffer = entry.mValue;
-        bgb.resource.buffer._0.offset = entry.mBufferOffset;
-        bgb.resource.buffer._0.size = entry.mBufferSize;
+        bgb.resource.buffer = {entry.mValue, entry.mBufferOffset, entry.mBufferSize};
         break;
       case SerialBindGroupEntryType::Texture:
         bgb.resource.tag = ffi::WGPUBindingResource_TextureView;
-        bgb.resource.texture_view._0 = entry.mValue;
+        bgb.resource.texture_view = {entry.mValue};
         break;
       case SerialBindGroupEntryType::Sampler:
         bgb.resource.tag = ffi::WGPUBindingResource_Sampler;
-        bgb.resource.sampler._0 = entry.mValue;
+        bgb.resource.sampler = {entry.mValue};
         break;
       default:
         MOZ_CRASH("unreachable");
