$NetBSD: patch-src_block_template.c,v 1.1 2017/03/07 23:17:51 sevan Exp $

CVE-2013-7459 backport
https://github.com/dlitz/pycrypto/commit/8dbe0dc3eea5c689d4f76b37b93fe216cf1f00d4

--- src/block_template.c.orig	2017-03-07 16:58:09.000000000 +0000
+++ src/block_template.c
@@ -170,6 +170,17 @@ ALGnew(PyObject *self, PyObject *args, P
 				"Key cannot be the null string");
 		return NULL;
 	}
+	if (IVlen != 0 && mode == MODE_ECB)
+	{
+		PyErr_Format(PyExc_ValueError, "ECB mode does not use IV");
+		return NULL;
+	}
+	if (IVlen != 0 && mode == MODE_CTR)
+	{
+		PyErr_Format(PyExc_ValueError,
+			"CTR mode needs counter parameter, not IV");
+		return NULL;
+	}
 	if (IVlen != BLOCK_SIZE && mode != MODE_ECB && mode != MODE_CTR)
 	{
 		PyErr_Format(PyExc_ValueError,
