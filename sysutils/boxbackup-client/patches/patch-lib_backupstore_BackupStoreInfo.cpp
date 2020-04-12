$NetBSD: patch-lib_backupstore_BackupStoreInfo.cpp,v 1.1 2020/04/12 19:45:51 joerg Exp $

No implicit conversion from uint32_t to int32_t or uint64_t to int64_t.

--- lib/backupstore/BackupStoreInfo.cpp.orig	2020-04-12 15:18:51.313053606 +0000
+++ lib/backupstore/BackupStoreInfo.cpp
@@ -151,15 +151,15 @@ void BackupStoreInfo::CreateNew(int32_t 
 	// Initial header (is entire file)
 	info_StreamFormat hdr = {
 		htonl(INFO_MAGIC_VALUE), // mMagicValue
-		htonl(AccountID), // mAccountID
+		(int32_t)htonl(AccountID), // mAccountID
 		0, // mClientStoreMarker
 		box_hton64(1), // mLastObjectIDUsed (which is the root directory)
 		0, // mBlocksUsed
 		0, // mBlocksInOldFiles
 		0, // mBlocksInDeletedFiles
 		0, // mBlocksInDirectories
-		box_hton64(BlockSoftLimit), // mBlocksSoftLimit
-		box_hton64(BlockHardLimit), // mBlocksHardLimit
+		(int64_t)box_hton64(BlockSoftLimit), // mBlocksSoftLimit
+		(int64_t)box_hton64(BlockHardLimit), // mBlocksHardLimit
 		0, // mCurrentMarkNumber
 		0, // mOptionsPresent
 		0 // mNumberDeletedDirectories
