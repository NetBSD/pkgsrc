$NetBSD: patch-Doc_library_cgi.rst,v 1.1.2.2 2021/10/13 21:04:01 tm Exp $

Fix CVE-2021-23336: Add `separator` argument to parse_qs; warn with default
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00359-CVE-2021-23336.patch

--- Doc/library/cgi.rst.orig	2020-04-19 21:13:39.000000000 +0000
+++ Doc/library/cgi.rst
@@ -285,10 +285,10 @@ These are useful if you want more contro
 algorithms implemented in this module in other circumstances.
 
 
-.. function:: parse(fp[, environ[, keep_blank_values[, strict_parsing]]])
+.. function:: parse(fp[, environ[, keep_blank_values[, strict_parsing[, separator]]]])
 
    Parse a query in the environment or from a file (the file defaults to
-   ``sys.stdin`` and environment defaults to ``os.environ``).  The *keep_blank_values* and *strict_parsing* parameters are
+   ``sys.stdin`` and environment defaults to ``os.environ``).  The *keep_blank_values*, *strict_parsing* and *separator* parameters are
    passed to :func:`urlparse.parse_qs` unchanged.
 
 
@@ -316,7 +316,6 @@ algorithms implemented in this module in
    Note that this does not parse nested multipart parts --- use
    :class:`FieldStorage` for that.
 
-
 .. function:: parse_header(string)
 
    Parse a MIME header (such as :mailheader:`Content-Type`) into a main value and a
