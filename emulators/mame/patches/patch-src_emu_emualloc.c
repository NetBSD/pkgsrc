$NetBSD: patch-src_emu_emualloc.c,v 1.1 2014/03/26 01:42:48 nat Exp $

This resolves a crash on startup.

--- src/emu/emualloc.c.orig	2013-10-15 22:14:50.000000000 +0000
+++ src/emu/emualloc.c
@@ -266,6 +266,11 @@ void resource_pool::add(resource_pool_it
 	memory_entry *entry = memory_entry::find(item.m_ptr);
 	if (entry == NULL)
 		entry = memory_entry::find(reinterpret_cast<UINT8 *>(item.m_ptr) - sizeof(size_t));
+	if (entry == NULL) {
+		osd_lock_release(m_listlock);
+		return;
+	}
+
 	assert(entry != NULL);
 	item.m_id = entry->m_id;
 	if (LOG_ALLOCS)
