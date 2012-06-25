$NetBSD: patch-src_jcode.h,v 1.1 2012/06/25 11:47:22 joerg Exp $

--- src/jcode.h.orig	2012-06-22 20:55:45.000000000 +0000
+++ src/jcode.h
@@ -31,7 +31,7 @@ enum {
 
 gchar *iconv_convert(const gchar *icode, const gchar *ocode, const gchar *inbuf);
 gchar *iconv_convert2(const gchar *icode, const gchar *ocode, const gchar *orig);
-inline gboolean isjisp(const gchar *buff);
+gboolean isjisp(const gchar *buff);
 gboolean iseuckanji(const guchar *buff);
 gboolean iseuchiragana(const guchar *buff);
 gboolean iseuckatakana(const guchar *buff);
