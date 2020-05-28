$NetBSD: patch-src_sljit_sljitProtExecAllocator.c,v 1.4 2020/05/28 07:53:05 wiz Exp $

cleanup alloc_chunk() in sljitProtExec for NetBSD
https://github.com/zherczeg/sljit/pull/40/commits

--- src/sljit/sljitProtExecAllocator.c.orig	2020-04-14 15:20:34.000000000 +0000
+++ src/sljit/sljitProtExecAllocator.c
@@ -220,28 +220,26 @@ static SLJIT_INLINE struct chunk_header*
 static SLJIT_INLINE struct chunk_header* alloc_chunk(sljit_uw size)
 {
 	struct chunk_header *retval;
-	void *maprx;
 
 	retval = (struct chunk_header *)mmap(NULL, size,
-			PROT_MPROTECT(PROT_EXEC|PROT_WRITE|PROT_READ),
-			MAP_ANON, -1, 0);
+			PROT_READ | PROT_WRITE | PROT_MPROTECT(PROT_EXEC),
+			MAP_ANON | MAP_SHARED, -1, 0);
 
 	if (retval == MAP_FAILED)
 		return NULL;
 
-	maprx = mremap(retval, size, NULL, size, MAP_REMAPDUP);
-	if (maprx == MAP_FAILED) {
+	retval->executable = mremap(retval, size, NULL, size, MAP_REMAPDUP);
+	if (retval->executable == MAP_FAILED) {
 		munmap((void *)retval, size);
 		return NULL;
 	}
 
-	if (mprotect(retval, size, PROT_READ | PROT_WRITE) == -1 ||
-		mprotect(maprx, size, PROT_READ | PROT_EXEC) == -1) {
-		munmap(maprx, size);
+	if (mprotect(retval->executable, size, PROT_READ | PROT_EXEC) == -1) {
+		munmap(retval->executable, size);
 		munmap((void *)retval, size);
 		return NULL;
 	}
-	retval->executable = maprx;
+
 	return retval;
 }
 #endif /* NetBSD >= 8 */
