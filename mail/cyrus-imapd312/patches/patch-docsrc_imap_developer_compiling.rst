$NetBSD: patch-docsrc_imap_developer_compiling.rst,v 1.1 2026/03/09 03:16:44 jnemeth Exp $

Replace external references to cyrussasl with actual links
to avoid web lookups while building.

--- docsrc/imap/developer/compiling.rst.orig	2026-01-19 06:24:23.189073716 +0000
+++ docsrc/imap/developer/compiling.rst
@@ -52,7 +52,7 @@ required to build a functional cyrus-ima
 .. _autoconf: http://www.gnu.org/software/autoconf/
 .. _automake: http://www.gnu.org/software/automake/
 .. _bison: http://www.gnu.org/software/bison/
-.. _Cyrus SASL: :ref:`Cyrus SASL <cyrussasl:sasl-index>`
+.. _Cyrus SASL: :ref:`Cyrus SASL <http://www.cyrusimap.org/sasl/>`
 .. _flex: http://flex.sourceforge.net/
 .. _gcc: http://gcc.gnu.org
 .. _gperf: http://www.gnu.org/software/gperf/
@@ -205,9 +205,9 @@ Other
 
 .. _ClamAV: https://www.clamav.net/
 .. _CUnit: http://cunit.sourceforge.net/
-.. _Cyrus SASL Plain: :ref:`Cyrus SASL <cyrussasl:sasl-index>`
-.. _Cyrus SASL MD5: :ref:`Cyrus SASL <cyrussasl:sasl-index>`
-.. _sasl binaries: :ref:`Cyrus SASL <cyrussasl:sasl-index>`
+.. _Cyrus SASL Plain: :ref:`Cyrus SASL <http://www.cyrusimap.org/sasl/>`
+.. _Cyrus SASL MD5: :ref:`Cyrus SASL <http://www.cyrusimap.org/sasl/>`
+.. _sasl binaries: :ref:`Cyrus SASL <http://www.cyrusimap.org/sasl/>`
 .. _Kerberos: http://web.mit.edu/kerberos/www/
 .. _libbrotli: https://github.com/google/brotli
 .. _libchardet: https://github.com/Joungkyun/libchardet
