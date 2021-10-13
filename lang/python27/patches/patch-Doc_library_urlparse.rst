$NetBSD: patch-Doc_library_urlparse.rst,v 1.1.2.2 2021/10/13 21:04:01 tm Exp $

Fix CVE-2021-23336: Add `separator` argument to parse_qs; warn with default
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00359-CVE-2021-23336.patch

--- Doc/library/urlparse.rst.orig	2020-04-19 21:13:39.000000000 +0000
+++ Doc/library/urlparse.rst
@@ -136,7 +136,7 @@ The :mod:`urlparse` module defines the f
       now raise :exc:`ValueError`.
 
 
-.. function:: parse_qs(qs[, keep_blank_values[, strict_parsing[, max_num_fields]]])
+.. function:: parse_qs(qs[, keep_blank_values[, strict_parsing[, max_num_fields[, separator]]]])
 
    Parse a query string given as a string argument (data of type
    :mimetype:`application/x-www-form-urlencoded`).  Data are returned as a
@@ -157,6 +157,15 @@ The :mod:`urlparse` module defines the f
    read. If set, then throws a :exc:`ValueError` if there are more than
    *max_num_fields* fields read.
 
+   The optional argument *separator* is the symbol to use for separating the
+   query arguments. It is recommended to set it to ``'&'`` or ``';'``.
+   It defaults to ``'&'``; a warning is raised if this default is used.
+   This default may be changed with the following environment variable settings:
+
+   - ``PYTHON_URLLIB_QS_SEPARATOR='&'``: use only ``&`` as separator, without warning (as in Python 3.6.13+ or 3.10)
+   - ``PYTHON_URLLIB_QS_SEPARATOR=';'``: use only ``;`` as separator
+   - ``PYTHON_URLLIB_QS_SEPARATOR=legacy``: use both ``&`` and ``;`` (as in previous versions of Python)
+
    Use the :func:`urllib.urlencode` function to convert such dictionaries into
    query strings.
 
@@ -186,6 +195,9 @@ The :mod:`urlparse` module defines the f
    read. If set, then throws a :exc:`ValueError` if there are more than
    *max_num_fields* fields read.
 
+   The optional argument *separator* is the symbol to use for separating the
+   query arguments. It works as in :py:func:`parse_qs`.
+
    Use the :func:`urllib.urlencode` function to convert such lists of pairs into
    query strings.
 
@@ -195,6 +207,7 @@ The :mod:`urlparse` module defines the f
    .. versionchanged:: 2.7.16
       Added *max_num_fields* parameter.
 
+
 .. function:: urlunparse(parts)
 
    Construct a URL from a tuple as returned by ``urlparse()``. The *parts* argument
