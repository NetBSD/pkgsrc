$NetBSD: patch-src_amd_vulkan_winsys_amdgpu_radv__amdgpu__cs.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Define ETIME if missing

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415
FreeBSD Bugzilla: Bug 225415 graphics/mesa-dri: update to 18.0.0 

--- src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c.orig	2018-02-09 02:17:57.000000000 +0000
+++ src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c
@@ -33,6 +33,9 @@
 #include "radv_amdgpu_bo.h"
 #include "sid.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 enum {
 	VIRTUAL_BUFFER_HASH_TABLE_SIZE = 1024
