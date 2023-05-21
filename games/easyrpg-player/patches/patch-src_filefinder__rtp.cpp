$NetBSD: patch-src_filefinder__rtp.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/filefinder_rtp.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/filefinder_rtp.cpp
@@ -170,7 +170,7 @@ void FileFinder_RTP::AddPath(StringView 
 	using namespace FileFinder;
 	auto fs = FileFinder::Root().Create(FileFinder::MakeCanonical(p));
 	if (fs) {
-		Output::Debug("Adding {} to RTP path", p);
+		Output::Debug("Adding {} to RTP path", std::string(p));
 
 		auto hit_info = RTP::Detect(fs, Player::EngineVersion());
 
