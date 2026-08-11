$NetBSD: patch-libtransmission_torrent-files.cc,v 1.1 2026/08/11 14:21:47 riastradh Exp $

Fix ctype(3) abuse.
https://gnats.NetBSD.org/60574

--- libtransmission/torrent-files.cc.orig	2024-05-29 01:38:35.000000000 +0000
+++ libtransmission/torrent-files.cc
@@ -335,13 +335,13 @@ namespace
     // Shortcut to avoid extra work below.
     // All the paths below involve filenames that begin with one of these chars
     static auto constexpr ReservedFilesBeginWithOneOf = "ACLNP"sv;
-    if (ReservedFilesBeginWithOneOf.find(toupper(in.front())) == std::string_view::npos)
+    if (ReservedFilesBeginWithOneOf.find(toupper(static_cast<unsigned char>(in.front()))) == std::string_view::npos)
     {
         return false;
     }
 
     auto in_upper = tr_pathbuf{ in };
-    std::transform(std::begin(in_upper), std::end(in_upper), std::begin(in_upper), [](auto ch) { return toupper(ch); });
+    std::transform(std::begin(in_upper), std::end(in_upper), std::begin(in_upper), [](auto ch) { return toupper(static_cast<unsigned char>(ch)); });
     auto const in_upper_sv = in_upper.sv();
 
     static auto constexpr ReservedNames = std::array<std::string_view, 22>{
