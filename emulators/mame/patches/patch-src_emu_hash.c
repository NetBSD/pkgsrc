$NetBSD: patch-src_emu_hash.c,v 1.1 2011/04/04 12:09:03 wiz Exp $

toupper is a macro on NetBSD.
Sent upstream.

--- src/emu/hash.c.orig	2011-03-29 09:38:54.000000000 +0000
+++ src/emu/hash.c
@@ -658,7 +658,7 @@ const char *hash_collection::macro_strin
 	buffer.reset();
 	for (hash_base *hash = m_hashlist.first(); hash != NULL; hash = hash->next())
 	{
-		buffer.cat(temp.cpy(hash->name()).toupper());
+		buffer.cat(temp.cpy(hash->name()).upper());
 		buffer.cat("(").cat(hash->string(temp)).cat(") ");
 	}
 
