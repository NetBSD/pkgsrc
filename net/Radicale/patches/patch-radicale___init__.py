$NetBSD: patch-radicale___init__.py,v 1.2 2017/03/20 10:49:03 sborrill Exp $

Add support for strip_domain
Fix reading of can_skip_base_prefix setting

--- radicale/__init__.py.orig	2016-01-07 22:29:49.000000000 +0000
+++ radicale/__init__.py	2017-03-20 10:43:49.000000000 +0000
@@ -249,7 +249,7 @@
         base_prefix = config.get("server", "base_prefix")
         if environ["PATH_INFO"].startswith(base_prefix):
             environ["PATH_INFO"] = environ["PATH_INFO"][len(base_prefix):]
-        elif config.get("server", "can_skip_base_prefix"):
+        elif config.getboolean("server", "can_skip_base_prefix"):
             log.LOGGER.debug(
                 "Prefix already stripped from path: %s", environ["PATH_INFO"])
         else:
@@ -280,6 +280,10 @@
             user = environ.get("REMOTE_USER")
             password = None
 
+        if config.getboolean("auth", "strip_domain"):
+            if user:
+                user = re.sub("@.*", "", user)
+
         well_known = WELL_KNOWN_RE.match(path)
         if well_known:
             redirect = config.get("well-known", well_known.group(1))
