$NetBSD: patch-approvaltests_version.py,v 1.1 2021/12/15 09:34:12 schmonz Exp $

Fix "NameError: name 'version_number' is not defined" to allow
module to load.

--- approvaltests/version.py.orig	2021-12-05 18:45:00.000000000 +0000
+++ approvaltests/version.py
@@ -1 +1 @@
-version="v3.3.0"
+version_number="v3.3.0"
