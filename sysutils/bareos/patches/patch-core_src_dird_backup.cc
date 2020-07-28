$NetBSD: patch-core_src_dird_backup.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Remove inadequate clutter in production messages

--- core/src/dird/backup.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/backup.cc
@@ -1194,7 +1194,9 @@ void GenerateBackupSummary(JobControlRec
         "  Last Volume Bytes:      %s (%sB)\n"
         "%s"                                        /* Daemon status info */
         "%s"                                        /* SecureErase status */
+#ifndef NO_ADV
         "  Bareos binary info:     %s\n"
+#endif
         "  Termination:            %s\n\n"),
         BAREOS, my_name, kBareosVersionStrings.Full, kBareosVersionStrings.ShortDate,
         HOST_OS, DISTNAME, DISTVER,
@@ -1222,7 +1224,9 @@ void GenerateBackupSummary(JobControlRec
         edit_uint64_with_suffix(mr.VolBytes, ec8),
         daemon_status.c_str(),
         secure_erase_status.c_str(),
+#ifndef NO_ADV
         kBareosVersionStrings.JoblogMessage,
+#endif
         TermMsg);
 
   /* clang-format on */
