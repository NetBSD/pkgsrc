$NetBSD: patch-libtransmission_utils.h,v 1.1 2026/08/11 14:21:47 riastradh Exp $

--- libtransmission/utils.h.orig	2026-06-29 23:12:56.000000000 +0000
+++ libtransmission/utils.h
@@ -94,7 +94,7 @@ template<typename T>
 [[nodiscard]] std::string tr_strlower(T in)
 {
     auto out = std::string{ std::move(in) };
-    std::for_each(std::begin(out), std::end(out), [](char& ch) { ch = std::tolower(ch); });
+    std::for_each(std::begin(out), std::end(out), [](char& ch) { ch = std::tolower(static_cast<unsigned char>(ch)); });
     return out;
 }
 
@@ -102,7 +102,7 @@ template<typename T>
 [[nodiscard]] std::string tr_strupper(T in)
 {
     auto out = std::string{ std::move(in) };
-    std::for_each(std::begin(out), std::end(out), [](char& ch) { ch = std::toupper(ch); });
+    std::for_each(std::begin(out), std::end(out), [](char& ch) { ch = std::toupper(static_cast<unsigned char>(ch)); });
     return out;
 }
 
