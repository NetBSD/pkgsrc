$NetBSD: patch-src_common_ac3.cpp,v 1.1 2023/05/29 19:51:25 wiz Exp $

https://gitlab.com/mbunkus/mkvtoolnix/-/commit/5a0a3502d496a1a0d0881dd001bcf5888c6f88a9

--- src/common/ac3.cpp.orig	2023-04-30 10:27:25.000000000 +0000
+++ src/common/ac3.cpp
@@ -381,7 +381,7 @@ frame_c::to_string(bool verbose)
                             get_effective_channel_layout());
 
   for (auto &frame : m_dependent_frames)
-    output += fmt::format(" { {0} }", frame.to_string(verbose));
+    output += fmt::format(" {{ {0} }}", frame.to_string(verbose));
 
   return output;
 }
