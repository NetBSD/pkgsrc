$NetBSD: patch-src_client_Response.hxx,v 1.1 2025/01/06 04:48:03 pho Exp $

Fix build with fmtlib-11. In this function S can be a type created by
fmtlib macro FMT_STRING(), which is actually a lambda function and cannot
be converted directly to fmt::string_view.

https://github.com/MusicPlayerDaemon/MPD/issues/2173

--- src/client/Response.hxx.orig	2025-01-06 04:21:57.888848307 +0000
+++ src/client/Response.hxx
@@ -83,7 +83,7 @@ public:
 	template<typename S, typename... Args>
 	bool Fmt(const S &format_str, Args&&... args) noexcept {
 #if FMT_VERSION >= 90000
-		return VFmt(format_str,
+		return VFmt(fmt::format_string<Args...>(format_str),
 			    fmt::make_format_args(args...));
 #elif FMT_VERSION >= 70000
 		return VFmt(fmt::to_string_view(format_str),
@@ -113,7 +113,7 @@ public:
 	void FmtError(enum ack code,
 		      const S &format_str, Args&&... args) noexcept {
 #if FMT_VERSION >= 90000
-		return VFmtError(code, format_str,
+		return VFmtError(code, fmt::format_string<Args...>(format_str),
 				 fmt::make_format_args(args...));
 #elif FMT_VERSION >= 70000
 		return VFmtError(code, fmt::to_string_view(format_str),
