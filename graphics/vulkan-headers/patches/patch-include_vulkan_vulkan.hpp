$NetBSD: patch-include_vulkan_vulkan.hpp,v 1.1 2021/01/24 18:57:46 maya Exp $

* add NetBSD support
*
--- include/vulkan/vulkan.hpp.orig	2019-12-02 17:52:14.520273368 +0000
+++ include/vulkan/vulkan.hpp
@@ -56,7 +56,7 @@
 # define VULKAN_HPP_ASSERT   assert
 #endif
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
 # include <dlfcn.h>
 #endif
 
