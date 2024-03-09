$NetBSD: patch-extras_tables_table-ldap_ber.h,v 1.1 2024/03/09 23:55:46 vins Exp $

Define _BEGIN_DECLS on SunOS

--- extras/tables/table-ldap/ber.h.orig	2024-03-09 22:45:06.596577402 +0000
+++ extras/tables/table-ldap/ber.h
@@ -20,6 +20,11 @@
 #ifndef _BER_H
 #define _BER_H
 
+#ifndef __BEGIN_DECLS
+# define __BEGIN_DECLS
+# define __END_DECLS
+#endif
+
 struct ber_octetstring {
 	size_t			 ostr_len;
 	const void		*ostr_val;
