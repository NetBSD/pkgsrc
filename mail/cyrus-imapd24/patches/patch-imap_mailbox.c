$NetBSD: patch-imap_mailbox.c,v 1.2 2012/03/12 13:40:12 obache Exp $

* cast to unsigned long for platform sizeof(time_t) > sizeof(unsigned long).
  https://bugzilla.cyrusimap.org/show_bug.cgi?id=3376

--- imap/mailbox.c.orig	2012-03-12 11:47:51.000000000 +0000
+++ imap/mailbox.c
@@ -1954,9 +1954,9 @@ bit32 make_sync_crc(struct mailbox *mail
     }
 
     snprintf(buf, 4096, "%u " MODSEQ_FMT " %lu (%u) %lu %s",
-	    record->uid, record->modseq, record->last_updated,
+	    record->uid, record->modseq, (unsigned long)record->last_updated,
 	    flagcrc,
-	    record->internaldate,
+	    (unsigned long)record->internaldate,
 	    message_guid_encode(&record->guid));
 
     return crc32_cstring(buf);
