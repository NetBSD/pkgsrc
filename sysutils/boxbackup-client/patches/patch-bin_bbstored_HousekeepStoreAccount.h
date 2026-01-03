$NetBSD: patch-bin_bbstored_HousekeepStoreAccount.h,v 1.1 2026/01/03 11:20:29 wiz Exp $

Add const to fix build problem with c++17.

--- bin/bbstored/HousekeepStoreAccount.h.orig	2026-01-03 11:16:17.775333729 +0000
+++ bin/bbstored/HousekeepStoreAccount.h
@@ -108,7 +108,7 @@ private:
 	
 	struct DelEnCompare
 	{
-		bool operator()(const DelEn &x, const DelEn &y);
+		bool operator()(const DelEn &x, const DelEn &y) const;
 	};
 	
 	int mAccountID;
