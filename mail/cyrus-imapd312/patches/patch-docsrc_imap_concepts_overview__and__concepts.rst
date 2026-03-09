$NetBSD: patch-docsrc_imap_concepts_overview__and__concepts.rst,v 1.1 2026/03/09 03:16:44 jnemeth Exp $

Replace external references to cyrussasl with actual links
to avoid web lookups while building.

--- docsrc/imap/concepts/overview_and_concepts.rst.orig	2026-01-19 06:22:12.989170023 +0000
+++ docsrc/imap/concepts/overview_and_concepts.rst
@@ -185,7 +185,7 @@ Login Authentication
 
 This section discusses different types of authentication (ways of logging in) that can be used with Cyrus IMAP.
 
-The Cyrus IMAP server uses the Cyrus SASL library for authentication. This section describes how to configure SASL with use with Cyrus imapd. Please consult the :ref:`Cyrus SASL System Administrator's Guide <cyrussasl:sasl-index>` for more detailed, up-to-date information.
+The Cyrus IMAP server uses the Cyrus SASL library for authentication. This section describes how to configure SASL with use with Cyrus imapd. Please consult the :ref:`Cyrus SASL System Administrator's Guide <http://www.cyrusimap.org/sasl/>` for more detailed, up-to-date information.
 
 Anonymous Login
 ===============
@@ -225,7 +225,7 @@ If the ``loginuseacl`` configuration opt
 Shared Secrets Logins
 =====================
 
-The SCRAM mechanisms require the user and the server to share a secret (generally a password) that can be used for comparison without actually passing the password in the clear across the network. For these mechanisms, you will need to supply a source of passwords, such as the sasldb (which is described more fully in the :ref:`Cyrus SASL distribution <cyrussasl:sasl-index>`).
+The SCRAM mechanisms require the user and the server to share a secret (generally a password) that can be used for comparison without actually passing the password in the clear across the network. For these mechanisms, you will need to supply a source of passwords, such as the sasldb (which is described more fully in the :ref:`Cyrus SASL distribution <http://www.cyrusimap.org/sasl/>`).
 
 Quotas
 ******
