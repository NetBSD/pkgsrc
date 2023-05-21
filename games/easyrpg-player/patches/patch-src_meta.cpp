$NetBSD: patch-src_meta.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/meta.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/meta.cpp
@@ -76,7 +76,7 @@ Meta::Meta(StringView meta_file) {
 		if (version == "1") {
 			IdentifyCanonName(TREEMAP_NAME, DATABASE_NAME);
 		} else {
-			Output::Warning("Metadata error in {}, format property {}:{} is missing or invalid: '{}'", meta_file, MTINI_EASY_RPG_SECTION, MTINI_FILE_FORMAT_VERSION, version);
+			Output::Warning("Metadata error in {}, format property {}:{} is missing or invalid: '{}'", std::string(meta_file), MTINI_EASY_RPG_SECTION, MTINI_FILE_FORMAT_VERSION, version);
 			ini = nullptr;
 		}
 	}
