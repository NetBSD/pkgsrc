$NetBSD: patch-lib_exabgp_application_healthcheck.py,v 1.1.2.2 2017/07/15 18:53:11 bsiegert Exp $

Provide a default syslog destination on NetBSD as well.
Fix spelling...

--- lib/exabgp/application/healthcheck.py.orig	2017-07-04 09:41:30.000000000 +0000
+++ lib/exabgp/application/healthcheck.py
@@ -203,11 +203,13 @@ def setup_logging (debug, silent, name, 
     """Setup logger"""
 
     def syslog_address():
-        """Return a sensitive syslog address"""
+        """Return a sensible syslog address"""
         if sys.platform == "darwin":
             return "/var/run/syslog"
         if sys.platform.startswith("freebsd"):
             return "/var/run/log"
+        if sys.platform.startswith("netbsd"):
+            return "/var/run/log"
         if sys.platform.startswith("linux"):
             return "/dev/log"
         raise EnvironmentError("Unable to guess syslog address for your "
