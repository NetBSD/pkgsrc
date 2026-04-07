$NetBSD: patch-lib_krb5_os_expand__path.c,v 1.1 2026/04/07 14:12:48 tnn Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f

--- lib/krb5/os/expand_path.c.orig	2026-04-07 12:39:38.893505164 +0000
+++ lib/krb5/os/expand_path.c
@@ -454,7 +454,8 @@ k5_expand_path_tokens_extra(krb5_context
 {
     krb5_error_code ret;
     struct k5buf buf;
-    char *tok_begin, *tok_end, *tok_val, **extra_tokens = NULL, *path;
+    const char *tok_begin, *tok_end;
+    char *tok_val, **extra_tokens = NULL, *path;
     const char *path_left;
     size_t nargs = 0, i;
     va_list ap;
