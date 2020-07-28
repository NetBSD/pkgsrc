$NetBSD: patch-core_src_stored_bscan.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Remove inadequate clutter in production messages

--- core/src/stored/bscan.cc.orig	2020-06-23 13:36:11.694151050 +0000
+++ core/src/stored/bscan.cc
@@ -1449,14 +1449,19 @@ static bool UpdateJobRecord(BareosDb* db
              "Volume Session Id:      %d\n"
              "Volume Session Time:    %d\n"
              "Last Volume Bytes:      %s\n"
+#ifndef NO_ADV
              "Bareos binary info:     %s\n"
+#endif
              "Termination:            %s\n\n"),
            edt, mjcr->JobId, mjcr->Job, mjcr->impl->fileset_name,
            job_level_to_str(mjcr->getJobLevel()), mjcr->client_name, sdt, edt,
            edit_uint64_with_commas(mjcr->JobFiles, ec1),
            edit_uint64_with_commas(mjcr->JobBytes, ec2), mjcr->VolSessionId,
            mjcr->VolSessionTime, edit_uint64_with_commas(mr.VolBytes, ec3),
-           kBareosVersionStrings.BinaryInfo, TermMsg);
+#ifndef NO_ADV
+           kBareosVersionStrings.BinaryInfo,
+#endif
+	   TermMsg);
   }
   FreeJcr(mjcr);
 
