$NetBSD: patch-components_vfs_filesystemarchive.cpp,v 1.1 2025/10/17 08:04:07 wiz Exp $

Add missing header for std::transform.

--- components/vfs/filesystemarchive.cpp.orig	2025-10-17 07:59:11.685470349 +0000
+++ components/vfs/filesystemarchive.cpp
@@ -4,6 +4,8 @@
 
 #include <components/debug/debuglog.hpp>
 
+#include <algorithm>
+
 namespace VFS
 {
 
