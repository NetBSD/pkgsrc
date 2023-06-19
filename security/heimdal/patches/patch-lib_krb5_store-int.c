$NetBSD: patch-lib_krb5_store-int.c,v 1.1 2023/06/19 19:13:03 riastradh Exp $

Fix CVE-2022-42898 for 32-bit systems.
https://github.com/heimdal/heimdal/issues/1161

--- lib/krb5/store-int.c.orig	2022-09-15 22:59:25.000000000 +0000
+++ lib/krb5/store-int.c
@@ -49,7 +49,7 @@ KRB5_LIB_FUNCTION krb5_ssize_t KRB5_LIB_
 _krb5_get_int64(void *buffer, uint64_t *value, size_t size)
 {
     unsigned char *p = buffer;
-    unsigned long v = 0;
+    uint64_t v = 0;
     size_t i;
     for (i = 0; i < size; i++)
 	v = (v << 8) + p[i];
