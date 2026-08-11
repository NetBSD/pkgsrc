$NetBSD: patch-libtransmission_file-win32.cc,v 1.1 2026/08/11 14:21:47 riastradh Exp $

--- libtransmission/file-win32.cc.orig	2026-06-29 23:12:56.000000000 +0000
+++ libtransmission/file-win32.cc
@@ -118,14 +118,14 @@ bool is_valid_path(std::string_view path
 {
     if (is_unc_path(path))
     {
-        if (path[2] != '\0' && isalnum(path[2]) == 0)
+        if (path[2] != '\0' && isalnum(static_cast<unsigned char>(path[2])) == 0)
         {
             return false;
         }
     }
     else if (auto const pos = path.find(':'); pos != std::string_view::npos)
     {
-        if (pos != 1 || isalpha(path[0]) == 0)
+        if (pos != 1 || isalpha(static_cast<unsigned char>(path[0])) == 0)
         {
             return false;
         }
@@ -448,13 +448,13 @@ bool tr_sys_path_is_relative(std::string
     }
 
     /* Local path: `X:` */
-    if (std::size(path) == 2 && isalpha(path[0]) != 0 && path[1] == ':')
+    if (std::size(path) == 2 && isalpha(static_cast<unsigned char>(path[0])) != 0 && path[1] == ':')
     {
         return false;
     }
 
     /* Local path: `X:\...`. */
-    if (std::size(path) > 2 && isalpha(path[0]) != 0 && path[1] == ':' && is_slash(path[2]))
+    if (std::size(path) > 2 && isalpha(static_cast<unsigned char>(path[0])) != 0 && path[1] == ':' && is_slash(path[2]))
     {
         return false;
     }
@@ -561,7 +561,7 @@ namespace
 {
 [[nodiscard]] bool isWindowsDeviceRoot(char ch) noexcept
 {
-    return isalpha(static_cast<int>(ch)) != 0;
+    return isalpha(static_cast<unsigned char>(ch)) != 0;
 }
 
 [[nodiscard]] constexpr bool isPathSeparator(char ch) noexcept
