$NetBSD: patch-DenyHosts_report.py,v 1.1 2022/10/15 20:29:48 he Exp $

Provide proper porting to python 3.

--- DenyHosts/report.py.orig	2015-06-27 16:22:43.000000000 +0000
+++ DenyHosts/report.py
@@ -1,8 +1,6 @@
 import logging
 import re
 import socket
-# Removing this as it causes runtime errors on Python3.4
-# from types import ListType, TupleType
 from .util import is_true
 try:
     import syslog
@@ -38,7 +36,7 @@ class Report:
     def add_section(self, message, iterable):
         self.report += "%s:\n\n" % message
         for i in iterable:
-            if type(i) in (TupleType, ListType):
+            if type(i) in (tuple, list):
                 extra = ": %d\n" % i[1]
                 i = i[0]
             else:
