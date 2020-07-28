$NetBSD: patch-core_src_dird_restore.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	remove inadequate clutter in status messages

--- core/src/dird/restore.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/restore.cc
@@ -562,7 +562,9 @@ void GenerateRestoreSummary(JobControlRe
              "  Bytes Restored:         %s\n"
              "  Rate:                   %.1f KB/s\n"
              "  SD termination status:  %s\n"
+#ifndef NO_ADV
              "  Bareos binary info:     %s\n"
+#endif
              "  Termination:            %s\n\n"),
            BAREOS, my_name, kBareosVersionStrings.Full,
            kBareosVersionStrings.ShortDate, HOST_OS, DISTNAME, DISTVER,
@@ -572,7 +574,11 @@ void GenerateRestoreSummary(JobControlRe
            edit_uint64_with_commas((uint64_t)jcr->impl->ExpectedFiles, ec1),
            edit_uint64_with_commas((uint64_t)jcr->impl->jr.JobFiles, ec2),
            edit_uint64_with_commas(jcr->impl->jr.JobBytes, ec3), (float)kbps,
-           sd_term_msg, kBareosVersionStrings.JoblogMessage, TermMsg);
+           sd_term_msg,
+#ifndef NO_ADV
+           kBareosVersionStrings.JoblogMessage,
+#endif
+           TermMsg);
       break;
     default:
       if (me->secure_erase_cmdline) {
@@ -607,7 +613,9 @@ void GenerateRestoreSummary(JobControlRe
              "  FD termination status:  %s\n"
              "  SD termination status:  %s\n"
              "%s"
+#ifndef NO_ADV
              "  Bareos binary info:     %s\n"
+#endif
              "  Termination:            %s\n\n"),
            BAREOS, my_name, kBareosVersionStrings.Full,
            kBareosVersionStrings.ShortDate, HOST_OS, DISTNAME, DISTVER,
@@ -618,7 +626,10 @@ void GenerateRestoreSummary(JobControlRe
            edit_uint64_with_commas((uint64_t)jcr->impl->jr.JobFiles, ec2),
            edit_uint64_with_commas(jcr->impl->jr.JobBytes, ec3), (float)kbps,
            jcr->JobErrors, fd_term_msg, sd_term_msg,
-           secure_erase_status.c_str(), kBareosVersionStrings.JoblogMessage,
+           secure_erase_status.c_str(),
+#ifndef NO_ADV
+	   kBareosVersionStrings.JoblogMessage,
+#endif
            TermMsg);
       break;
   }
