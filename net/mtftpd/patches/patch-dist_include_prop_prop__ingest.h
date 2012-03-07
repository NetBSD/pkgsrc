$NetBSD: patch-dist_include_prop_prop__ingest.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/include/prop/prop_ingest.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_ingest.h	2012-03-02 20:17:16.790210908 +0100
@@ -78,6 +78,8 @@ typedef struct {
 #define	PROP_INGEST_END							\
 	{ .pite_key = NULL }
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 prop_ingest_context_t
 		prop_ingest_context_alloc(void *);
