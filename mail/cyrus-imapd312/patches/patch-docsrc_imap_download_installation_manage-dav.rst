$NetBSD: patch-docsrc_imap_download_installation_manage-dav.rst,v 1.1 2026/03/09 03:16:44 jnemeth Exp $

Replace external references to cyrussasl with actual links
to avoid web lookups while building.

--- docsrc/imap/download/installation/manage-dav.rst.orig	2026-01-19 06:25:46.418639235 +0000
+++ docsrc/imap/download/installation/manage-dav.rst
@@ -67,7 +67,7 @@ Authentication
 --------------
 
 As with other Cyrus services, the Cyrus httpd service uses
-:ref:`Cyrus SASL <cyrussasl:sasl-index>` to perform its authentication.
+:ref:`Cyrus SASL <http://www.cyrusimap.org/sasl/>` to perform its authentication.
 
 .. sidebar:: allowplaintext
 
@@ -84,7 +84,7 @@ whether the client has connected over a 
 authentication does not depend on a Cyrus SASL plugin.
 
 The advertisement of the other HTTP authentication schemes is controlled by the
-:ref:`SASL mech_list option <cyrussasl:options>` option. For Cyrus httpd
+:ref:`SASL mech_list option <http://www.cyrusimap.org/sasl/sasl/options.html>` option. For Cyrus httpd
 the GSS-SPNEGO, SCRAM-SHA-1, and SCRAM-SHA-256 values enable
 support for the Negotiate (Kerberos only), SCRAM-SHA-1, and
 SCRAM-SHA-256 authentication schemes respectively, provided that the plugins
