$NetBSD: patch-src_command_FileCommands.cxx,v 1.1 2023/05/17 10:45:41 wiz Exp $

Fix build with fmtlib 10. Remove after 0.23.13.

--- src/command/FileCommands.cxx.orig	2023-01-17 17:54:47.000000000 +0000
+++ src/command/FileCommands.cxx
@@ -132,7 +132,7 @@ public:
 
 	void OnPair(StringView key, StringView value) noexcept override {
 		if (IsValidName(key) && IsValidValue(value))
-			response.Fmt(FMT_STRING("{}: {}\n"), key, value);
+			response.Fmt(FMT_STRING("{}: {}\n"), std::string(key), std::string(value));
 	}
 };
 
