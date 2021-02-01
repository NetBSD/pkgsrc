$NetBSD: patch-core_src_filed_accurate__lmdb.cc,v 1.2 2021/02/01 09:08:43 kardel Exp $

	avoid uninitialized member crash.
	lmdb not verified to be working correctly though.

--- core/src/filed/accurate_lmdb.cc.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/src/filed/accurate_lmdb.cc
@@ -45,6 +45,7 @@ static int debuglevel = 100;
 BareosAccurateFilelistLmdb::BareosAccurateFilelistLmdb(JobControlRecord* jcr,
                                                        uint32_t number_of_files)
 {
+  jcr_ = jcr;
   filenr_ = 0;
   pay_load_ = GetPoolMemory(PM_MESSAGE);
   lmdb_name_ = GetPoolMemory(PM_FNAME);
