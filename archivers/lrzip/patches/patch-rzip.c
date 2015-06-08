$NetBSD: patch-rzip.c,v 1.1 2015/06/08 14:58:09 wiedi Exp $

Use same platform check as in lrzip_private.h file. The fake_mremap is required
on all platforms that are not linux.

--- rzip.c.orig	2015-03-10 10:13:22.000000000 +0000
+++ rzip.c
@@ -772,7 +772,7 @@ static inline void init_hash_indexes(str
 		st->hash_index[i] = ((random() << 16) ^ random());
 }
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if !defined(__linux)
 # define mremap fake_mremap
 
 static inline void *fake_mremap(void *old_address, size_t old_size, size_t new_size, int flags __UNUSED__)
