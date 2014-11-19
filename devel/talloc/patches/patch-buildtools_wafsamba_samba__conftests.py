$NetBSD: patch-buildtools_wafsamba_samba__conftests.py,v 1.1 2014/11/19 15:36:26 schmonz Exp $

Don't build and install the man page just because xsltproc happens
to find docbook.xsl on a given system.

--- buildtools/wafsamba/samba_conftests.py.orig	2013-06-04 14:21:30.000000000 +0000
+++ buildtools/wafsamba/samba_conftests.py
@@ -491,6 +491,8 @@ def CHECK_INLINE(conf):
 @conf
 def CHECK_XSLTPROC_MANPAGES(conf):
     '''check if xsltproc can run with the given stylesheets'''
+    if "pkgsrc":
+        return False
 
 
     if not conf.CONFIG_SET('XSLTPROC'):
