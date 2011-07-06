$NetBSD: patch-imap_mailbox.c,v 1.1 2011/07/06 09:45:45 obache Exp $

* cast to unsigned long for platform sizeof(time_t) > sizeof(unsigned long).
  https://bugzilla.cyrusimap.org/show_bug.cgi?id=3376

--- imap/mailbox.c.orig	2011-07-04 15:05:01.000000000 +0000
+++ imap/mailbox.c
@@ -1918,9 +1918,9 @@ bit32 make_sync_crc(struct mailbox *mail
     }
 
     snprintf(buf, 4096, "%u " MODSEQ_FMT " %lu (%u) %lu %s",
-	    record->uid, record->modseq, record->last_updated,
+	    record->uid, record->modseq, (unsigned long)record->last_updated,
 	    flagcrc,
-	    record->internaldate,
+	    (unsigned long)record->internaldate,
 	    message_guid_encode(&record->guid));
 
     return crc32_cstring(buf);
