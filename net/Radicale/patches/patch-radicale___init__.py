$NetBSD: patch-radicale___init__.py,v 1.1 2017/03/17 16:56:47 sborrill Exp $

Add support for strip_domain
Fix reading of can_skip_base_prefix setting

--- radicale/__init__.py.orig	2017-03-17 16:04:32.000000000 +0000
+++ radicale/__init__.py	2017-03-17 16:04:57.000000000 +0000
@@ -249,7 +249,7 @@
         base_prefix = config.get("server", "base_prefix")
         if environ["PATH_INFO"].startswith(base_prefix):
             environ["PATH_INFO"] = environ["PATH_INFO"][len(base_prefix):]
-        elif config.get("server", "can_skip_base_prefix"):
+        elif config.getboolean("server", "can_skip_base_prefix"):
             log.LOGGER.debug(
                 "Prefix already stripped from path: %s", environ["PATH_INFO"])
         else:
@@ -280,6 +280,9 @@
             user = environ.get("REMOTE_USER")
             password = None
 
+        if config.getboolean("auth", "strip_domain"):
+            user = re.sub("@.*", "", user)
+
         well_known = WELL_KNOWN_RE.match(path)
         if well_known:
             redirect = config.get("well-known", well_known.group(1))
