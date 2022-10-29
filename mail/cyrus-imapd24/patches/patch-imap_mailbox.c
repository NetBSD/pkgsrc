$NetBSD: patch-imap_mailbox.c,v 1.4 2022/10/29 14:44:07 he Exp $

* cast to unsigned long for platform sizeof(time_t) > sizeof(unsigned long).
  https://bugzilla.cyrusimap.org/show_bug.cgi?id=3376
* Fix an issue related to use of the assert() macro (statement or block?)

--- imap/mailbox.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ imap/mailbox.c
@@ -1961,10 +1961,10 @@ bit32 make_sync_crc(struct mailbox *mail
 	flagcrc ^= crc32_cstring(buf);
     }
 
-    snprintf(buf, 4096, "%u " MODSEQ_FMT " %lu (%u) %lu %s",
-	    record->uid, record->modseq, record->last_updated,
+    snprintf(buf, 4096, "%u " MODSEQ_FMT " " MODSEQ_FMT " (%u) " MODSEQ_FMT " %s",
+	    record->uid, record->modseq, (modseq_t)record->last_updated,
 	    flagcrc,
-	    record->internaldate,
+	    (modseq_t)record->internaldate,
 	    message_guid_encode(&record->guid));
 
     return crc32_cstring(buf);
@@ -2179,7 +2179,7 @@ int mailbox_append_index_record(struct m
     assert(mailbox_index_islocked(mailbox, 1));
 
     /* Append MUST be a higher UID than any we've yet seen */
-    assert(record->uid > mailbox->i.last_uid)
+    assert(record->uid > mailbox->i.last_uid);
 
     /* Append MUST have a message with data */
     assert(record->size);
