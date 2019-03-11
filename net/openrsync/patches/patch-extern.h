$NetBSD: patch-extern.h,v 1.1 2019/03/11 16:27:03 kamil Exp $

Add fallback declarations of functions missing on !OpenBSD.

--- extern.h.orig	2019-02-21 15:41:00.000000000 +0000
+++ extern.h
@@ -383,6 +383,12 @@ int		  idents_recv(struct sess *, int, s
 void		  idents_remap(struct sess *, int, struct ident *, size_t);
 int		  idents_send(struct sess *, int, const struct ident *, size_t);
 
+#ifndef __OpenBSD__
+void *recallocarray(void *ptr, size_t oldnmemb, size_t nmemb, size_t size);
+int pledge(const char *promises, const char *execpromises);
+int unveil(const char *path, const char *permissions);
+#endif
+
 __END_DECLS
 
 #endif /*!EXTERN_H*/
