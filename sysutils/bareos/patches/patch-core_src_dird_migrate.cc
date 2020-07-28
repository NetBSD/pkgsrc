$NetBSD: patch-core_src_dird_migrate.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	remove inadequate clutter in status messages

--- core/src/dird/migrate.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/dird/migrate.cc
@@ -1764,7 +1764,9 @@ static inline void GenerateMigrateSummar
            "  Last Volume Bytes:      %s (%sB)\n"
            "  SD Errors:              %d\n"
            "  SD termination status:  %s\n"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
          BAREOS, my_name, kBareosVersionStrings.Full,
          kBareosVersionStrings.ShortDate, HOST_OS, DISTNAME, DISTVER,
@@ -1798,7 +1800,11 @@ static inline void GenerateMigrateSummar
          mig_jcr ? mig_jcr->VolumeName : _("*None*"), jcr->VolSessionId,
          jcr->VolSessionTime, edit_uint64_with_commas(mr->VolBytes, ec4),
          edit_uint64_with_suffix(mr->VolBytes, ec5), jcr->impl->SDErrors,
-         sd_term_msg, kBareosVersionStrings.JoblogMessage, term_code);
+         sd_term_msg,
+#ifndef NO_ADV
+         kBareosVersionStrings.JoblogMessage,
+#endif
+         term_code);
   } else {
     /*
      * Copy/Migrate selection only Job.
@@ -1813,14 +1819,20 @@ static inline void GenerateMigrateSummar
            "  End time:               %s\n"
            "  Elapsed time:           %s\n"
            "  Priority:               %d\n"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
          BAREOS, my_name, kBareosVersionStrings.Full,
          kBareosVersionStrings.ShortDate, HOST_OS, DISTNAME, DISTVER,
          edit_uint64(jcr->impl->jr.JobId, ec8), jcr->impl->jr.Job,
          jcr->impl->res.catalog->resource_name_, jcr->impl->res.catalog_source,
          sdt, edt, edit_utime(RunTime, elapsed, sizeof(elapsed)),
-         jcr->JobPriority, kBareosVersionStrings.JoblogMessage, term_code);
+         jcr->JobPriority,
+#ifndef NO_ADV
+         kBareosVersionStrings.JoblogMessage,
+#endif
+         term_code);
   }
 }
 
