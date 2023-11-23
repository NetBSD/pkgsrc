$NetBSD: patch-axfer_xfer-options.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- axfer/xfer-options.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ axfer/xfer-options.c
@@ -447,7 +447,8 @@ static int generate_path_with_suffix(str
 
 static int generate_path_without_suffix(struct xfer_context *xfer,
 				        const char *template,
-					unsigned int index, const char *)
+					unsigned int index,
+					const char *suffix ATTRIBUTE_UNUSED)
 {
 	static const char *const single_format = "%s";
 	static const char *const multiple_format = "%s-%i";
