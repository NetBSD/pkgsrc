$NetBSD: patch-lib_krb5_asn.1_asn1buf.h,v 1.1 2011/06/01 09:57:23 adam Exp $

Clang does not like this kind of inlines.

--- lib/krb5/asn.1/asn1buf.h.orig	2011-06-01 09:47:31.000000000 +0000
+++ lib/krb5/asn.1/asn1buf.h
@@ -147,7 +147,7 @@ asn1_error_code asn1buf_insert_octet(asn
  * effects   Inserts o into the buffer *buf, expanding the buffer if
  *           necessary.  Returns ENOMEM memory is exhausted.
  */
-#if ((__GNUC__ >= 2) && !defined(ASN1BUF_OMIT_INLINE_FUNCS)) && !defined(CONFIG_SMALL)
+#if ((__GNUC__ >= 2) && !defined(__clang__) && !defined(ASN1BUF_OMIT_INLINE_FUNCS)) && !defined(CONFIG_SMALL)
 extern __inline__ asn1_error_code asn1buf_insert_octet(asn1buf *buf, const int o)
 {
     asn1_error_code retval;
