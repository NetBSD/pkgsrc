$NetBSD: patch-core_src_dird_consolidate.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Remove inadequate clutter in production messages

--- core/src/dird/consolidate.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/consolidate.cc
@@ -384,11 +384,16 @@ void ConsolidateCleanup(JobControlRecord
          "  Scheduled time:         %s\n"
          "  Start time:             %s\n"
          "  End time:               %s\n"
+#ifndef NO_ADV
          "  Bareos binary info:     %s\n"
+#endif
          "  Termination:            %s\n\n"),
        kBareosVersionStrings.Full, kBareosVersionStrings.ShortDate, edt,
        jcr->impl->jr.JobId, jcr->impl->jr.Job, schedt, sdt, edt,
-       kBareosVersionStrings.JoblogMessage, TermMsg);
+#ifndef NO_ADV
+       kBareosVersionStrings.JoblogMessage,
+#endif
+       TermMsg);
 
   Dmsg0(debuglevel, "Leave ConsolidateCleanup()\n");
 }
