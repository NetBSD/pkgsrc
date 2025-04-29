$NetBSD: patch-lib_include_uhdlib_usrp_dboard_fbx_fbx__constants.hpp,v 1.1 2025/04/29 09:17:25 tnn Exp $

https://github.com/EttusResearch/uhd/commit/14337e23e4e073be5377dbcefc96ed04515ac51a.patch

--- lib/include/uhdlib/usrp/dboard/fbx/fbx_constants.hpp.orig	2025-01-27 14:59:07.000000000 +0000
+++ lib/include/uhdlib/usrp/dboard/fbx/fbx_constants.hpp
@@ -10,6 +10,7 @@
 #include <unordered_map>
 #include <array>
 #include <cstddef>
+#include <cstdint>
 #include <cstring>
 #include <list>
 #include <map>
