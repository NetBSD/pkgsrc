$NetBSD: patch-src_pages.c,v 1.7 2023/05/31 21:04:17 christos Exp $

Don't affect global state when making alignment modifications to the
mmap flags.

diff --git a/src/pages.c b/src/pages.c
index 09b51b88..2d5b8164 100644
--- src/pages.c
+++ src/pages.c
@@ -155,6 +155,7 @@ os_pages_map(void *addr, size_t size, size_t alignment, bool *commit) {
 	 * of existing mappings, and we only want to create new mappings.
 	 */
 	{
+		int flags = mmap_flags;
 #ifdef __NetBSD__
 		/*
 		 * On NetBSD PAGE for a platform is defined to the
@@ -164,12 +165,12 @@ os_pages_map(void *addr, size_t size, size_t alignment, bool *commit) {
 		 */
 		if (alignment > os_page || PAGE > os_page) {
 			unsigned int a = ilog2(MAX(alignment, PAGE));
-			mmap_flags |= MAP_ALIGNED(a);
+			flags |= MAP_ALIGNED(a);
 		}
 #endif
 		int prot = *commit ? PAGES_PROT_COMMIT : PAGES_PROT_DECOMMIT;
 
-		ret = mmap(addr, size, prot, mmap_flags, PAGES_FD_TAG, 0);
+		ret = mmap(addr, size, prot, flags, PAGES_FD_TAG, 0);
 	}
 	assert(ret != NULL);
 
