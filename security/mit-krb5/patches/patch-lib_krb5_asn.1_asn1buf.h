$NetBSD: patch-lib_krb5_asn.1_asn1buf.h,v 1.2 2016/03/15 15:16:39 tez Exp $

Clang does not like this kind of inlines.

--- lib/krb5/asn.1/asn1buf.h.orig	2016-02-29 19:50:13.000000000 +0000
+++ lib/krb5/asn.1/asn1buf.h
@@ -107,7 +107,7 @@ void asn1buf_destroy(asn1buf **buf);
  * effects   Inserts o into the buffer *buf, expanding the buffer if
  *           necessary.  Returns ENOMEM memory is exhausted.
  */
-#if ((__GNUC__ >= 2) && !defined(ASN1BUF_OMIT_INLINE_FUNCS)) && !defined(CONFIG_SMALL)
+#if ((__GNUC__ >= 2) && !defined(__clang__) && !defined(ASN1BUF_OMIT_INLINE_FUNCS)) && !defined(CONFIG_SMALL)
 static inline asn1_error_code
 asn1buf_insert_octet(asn1buf *buf, const int o)
 {
