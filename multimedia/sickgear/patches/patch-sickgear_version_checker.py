$NetBSD: patch-sickgear_version_checker.py,v 1.1 2024/07/08 15:15:59 js Exp $

--- sickgear/version_checker.py.orig	2024-07-08 15:03:22.387739566 +0000
+++ sickgear/version_checker.py
@@ -30,7 +30,6 @@ from exceptions_helper import ex
 import sickgear
 from . import logger, notifiers, ui
 from .scheduler import (Scheduler, Job)
-from .piper import check_pip_outdated
 from sg_helpers import cmdline_runner, get_url
 
 # noinspection PyUnresolvedReferences
@@ -81,7 +80,6 @@ class PackagesUpdater(Job):
             return False
 
         logger.log('Checking for %s%s' % (self.install_type, ('', ' (from menu)')[force]))
-        sickgear.UPDATES_TODO = check_pip_outdated(force)
         if not sickgear.UPDATES_TODO:
             msg = 'No %s needed' % self.install_type
             logger.log(msg)
