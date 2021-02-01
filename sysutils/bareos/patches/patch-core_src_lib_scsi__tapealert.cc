$NetBSD: patch-core_src_lib_scsi__tapealert.cc,v 1.2 2021/02/01 09:08:43 kardel Exp $

	fix result bit setting by keeping the uint64_t type and
	not trip over endian issues and off by one errors for
	result_index == 64.

--- core/src/lib/scsi_tapealert.cc.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/src/lib/scsi_tapealert.cc
@@ -172,7 +172,7 @@ bool GetTapealertFlags(int fd, const cha
           if (result_index == tapealert_mappings[j].flag) {
             Dmsg2(100, "TapeAlert [%d] set ==> %s\n", result_index,
                   tapealert_mappings[j].alert_msg);
-            SetBit(result_index, (char*)flags);
+            *flags |= 1UL << (result_index - 1);
           }
         }
       }
