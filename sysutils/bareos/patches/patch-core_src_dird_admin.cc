$NetBSD: patch-core_src_dird_admin.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Remove inadequate clutter in production messages

--- core/src/dird/admin.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/admin.cc
@@ -120,10 +120,15 @@ void AdminCleanup(JobControlRecord* jcr,
          "  Scheduled time:         %s\n"
          "  Start time:             %s\n"
          "  End time:               %s\n"
+#ifndef NO_ADV
          "  Bareos binary info:     %s\n"
+#endif
          "  Termination:            %s\n\n"),
        kBareosVersionStrings.Full, kBareosVersionStrings.ShortDate, edt, jcr->impl->jr.JobId,
-       jcr->impl->jr.Job, schedt, sdt, edt, kBareosVersionStrings.JoblogMessage,
+       jcr->impl->jr.Job, schedt, sdt, edt,
+#ifndef NO_ADV
+       kBareosVersionStrings.JoblogMessage,
+#endif
        TermMsg);
 
   Dmsg0(debuglevel, "Leave AdminCleanup()\n");
