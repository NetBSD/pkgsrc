$NetBSD: patch-Doc_library_mailcap.rst,v 1.1 2022/08/11 01:32:50 gutteridge Exp $

Fix CVE-2015-20107: Make mailcap refuse to match unsafe filenames/types/params

Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/a9b12e85bd4d3280e07bc3bfa72a9f2b674cb4ff/f/00382-cve-2015-20107.patch

--- Doc/library/mailcap.rst.orig	2020-04-19 21:13:39.000000000 +0000
+++ Doc/library/mailcap.rst
@@ -54,6 +54,18 @@ standard.  However, mailcap files are su
    use) to determine whether or not the mailcap line applies.  :func:`findmatch`
    will automatically check such conditions and skip the entry if the check fails.
 
+   .. versionchanged:: 3.11
+
+      To prevent security issues with shell metacharacters (symbols that have
+      special effects in a shell command line), ``findmatch`` will refuse
+      to inject ASCII characters other than alphanumerics and ``@+=:,./-_``
+      into the returned command line.
+
+      If a disallowed character appears in *filename*, ``findmatch`` will always
+      return ``(None, None)`` as if no entry was found.
+      If such a character appears elsewhere (a value in *plist* or in *MIMEtype*),
+      ``findmatch`` will ignore all mailcap entries which use that value.
+      A :mod:`warning <warnings>` will be raised in either case.
 
 .. function:: getcaps()
 
