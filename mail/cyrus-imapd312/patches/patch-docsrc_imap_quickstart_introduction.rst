$NetBSD: patch-docsrc_imap_quickstart_introduction.rst,v 1.1 2026/03/09 03:16:44 jnemeth Exp $

Replace external references to cyrussasl with actual links
to avoid web lookups while building.

--- docsrc/imap/quickstart/introduction.rst.orig	2026-01-19 06:35:00.097077895 +0000
+++ docsrc/imap/quickstart/introduction.rst
@@ -8,7 +8,7 @@ Cyrus IMAP is a `Carnegie Mellon Univers
 development project for a highly scalable enterprise mail system.
 
 Cyrus IMAP is one of two primary software development projects
-undertaken by the Cyrus project -- the other one being :ref:`cyrussasl:sasl-index`.
+undertaken by the Cyrus project -- the other one being :ref:`http://www.cyrusimap.org/sasl/`.
 
 The project as a whole started in 1994 and has its roots in replacing
 the Andrew Mail System (|AMS|) that |CMU| had been using, and has
