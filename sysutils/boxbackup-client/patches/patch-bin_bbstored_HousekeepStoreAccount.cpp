$NetBSD: patch-bin_bbstored_HousekeepStoreAccount.cpp,v 1.1 2026/01/03 11:20:29 wiz Exp $

Add const to fix build problem with c++17.

--- bin/bbstored/HousekeepStoreAccount.cpp.orig	2026-01-03 11:14:28.618627983 +0000
+++ bin/bbstored/HousekeepStoreAccount.cpp
@@ -655,7 +655,7 @@ bool HousekeepStoreAccount::ScanDirector
 //		Created: 11/12/03
 //
 // --------------------------------------------------------------------------
-bool HousekeepStoreAccount::DelEnCompare::operator()(const HousekeepStoreAccount::DelEn &x, const HousekeepStoreAccount::DelEn &y)
+bool HousekeepStoreAccount::DelEnCompare::operator()(const HousekeepStoreAccount::DelEn &x, const HousekeepStoreAccount::DelEn &y) const
 {
 	// STL spec says this:
 	// A Strict Weak Ordering is a Binary Predicate that compares two objects, returning true if the first precedes the second. 
