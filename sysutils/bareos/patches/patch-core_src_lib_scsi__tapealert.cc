$NetBSD: patch-core_src_lib_scsi__tapealert.cc,v 1.1 2020/08/21 06:01:36 kardel Exp $

	fix result bit setting by keeping the uint64_t type and
	not trip over endian issues and off by one errors for
	result_index == 64.

--- core/src/lib/scsi_tapealert.cc.orig	2020-08-20 16:04:40.584902268 +0000
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
