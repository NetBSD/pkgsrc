$NetBSD: patch-core_src_dird_verify.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	remove inadequate clutter in status messages

--- core/src/dird/verify.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/verify.cc
@@ -567,7 +567,9 @@ void VerifyCleanup(JobControlRecord* jcr
              "  Non-fatal FD errors:    %d\n"
              "  FD termination status:  %s\n"
              "  SD termination status:  %s\n"
+#ifndef NO_ADV
              "  Bareos binary info:     %s\n"
+#endif
              "  Termination:            %s\n\n"),
            BAREOS, my_name, kBareosVersionStrings.Full,
            kBareosVersionStrings.ShortDate, HOST_OS, DISTNAME, DISTVER,
@@ -577,7 +579,10 @@ void VerifyCleanup(JobControlRecord* jcr
            Name, sdt, edt,
            edit_uint64_with_commas(jcr->impl->ExpectedFiles, ec1),
            edit_uint64_with_commas(jcr->JobFiles, ec2), jcr->JobErrors,
-           fd_term_msg, sd_term_msg, kBareosVersionStrings.JoblogMessage,
+           fd_term_msg, sd_term_msg,
+#ifndef NO_ADV
+	   kBareosVersionStrings.JoblogMessage,
+#endif
            TermMsg);
       break;
     default:
@@ -596,7 +601,9 @@ void VerifyCleanup(JobControlRecord* jcr
              "  Files Examined:         %s\n"
              "  Non-fatal FD errors:    %d\n"
              "  FD termination status:  %s\n"
+#ifndef NO_ADV
              "  Bareos binary info:     %s\n"
+#endif
              "  Termination:            %s\n\n"),
            BAREOS, my_name, kBareosVersionStrings.Full,
            kBareosVersionStrings.ShortDate, HOST_OS, DISTNAME, DISTVER,
@@ -604,7 +611,10 @@ void VerifyCleanup(JobControlRecord* jcr
            jcr->impl->res.fileset->resource_name_, JobLevelToString(JobLevel),
            jcr->impl->res.client->resource_name_, jcr->impl->previous_jr.JobId,
            Name, sdt, edt, edit_uint64_with_commas(jcr->JobFiles, ec1),
-           jcr->JobErrors, fd_term_msg, kBareosVersionStrings.JoblogMessage,
+           jcr->JobErrors, fd_term_msg,
+#ifndef NO_ADV
+	   kBareosVersionStrings.JoblogMessage,
+#endif
            TermMsg);
       break;
   }
