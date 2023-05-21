$NetBSD: patch-src_output.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/output.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/output.cpp
@@ -304,7 +304,7 @@ bool Output::TakeScreenshot(StringView f
 	auto ret = FileFinder::Save().OpenOutputStream(file, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
 
 	if (ret) {
-		Output::Debug("Saving Screenshot {}", file);
+		Output::Debug("Saving Screenshot {}", std::string(file));
 		return Output::TakeScreenshot(ret);
 	}
 	return false;
