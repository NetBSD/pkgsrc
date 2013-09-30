$NetBSD: patch-calypso_____init____.py,v 1.1 2013/09/30 09:35:55 wiz Exp $

Fix version number. Accepted upstream.

--- calypso/__init__.py.orig	2013-09-20 17:59:23.000000000 +0000
+++ calypso/__init__.py
@@ -61,7 +61,7 @@ formatter = logging.Formatter("%(message
 ch.setFormatter (formatter)
 log.addHandler(ch)
 
-VERSION = "1.1"
+VERSION = "1.2"
 
 def _check(request, function):
     """Check if user has sufficient rights for performing ``request``."""
