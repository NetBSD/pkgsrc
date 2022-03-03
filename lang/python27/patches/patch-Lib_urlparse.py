$NetBSD: patch-Lib_urlparse.py,v 1.2.2.1 2022/03/03 19:33:58 bsiegert Exp $

Fix CVE-2021-23336: Add `separator` argument to parse_qs; warn with default
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00359-CVE-2021-23336.patch

Fix CVE-2022-0391: urlparse does not sanitize URLs containing ASCII newline and tabs
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/40dd05e5d77dbfa81777c9f84b704bc2239bf710/f/00377-CVE-2022-0391.patch

--- Lib/urlparse.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/urlparse.py
@@ -29,6 +29,7 @@ test_urlparse.py provides a good indicat
 """
 
 import re
+import os
 
 __all__ = ["urlparse", "urlunparse", "urljoin", "urldefrag",
            "urlsplit", "urlunsplit", "parse_qs", "parse_qsl"]
@@ -62,6 +63,9 @@ scheme_chars = ('abcdefghijklmnopqrstuvw
                 '0123456789'
                 '+-.')
 
+# Unsafe bytes to be removed per WHATWG spec
+_UNSAFE_URL_BYTES_TO_REMOVE = ['\t', '\r', '\n']
+
 MAX_CACHE_SIZE = 20
 _parse_cache = {}
 
@@ -184,12 +188,19 @@ def _checknetloc(netloc):
                              "under NFKC normalization"
                              % netloc)
 
+def _remove_unsafe_bytes_from_url(url):
+    for b in _UNSAFE_URL_BYTES_TO_REMOVE:
+        url = url.replace(b, "")
+    return url
+
 def urlsplit(url, scheme='', allow_fragments=True):
     """Parse a URL into 5 components:
     <scheme>://<netloc>/<path>?<query>#<fragment>
     Return a 5-tuple: (scheme, netloc, path, query, fragment).
     Note that we don't break the components up in smaller bits
     (e.g. netloc is a single string) and we don't expand % escapes."""
+    url = _remove_unsafe_bytes_from_url(url)
+    scheme = _remove_unsafe_bytes_from_url(scheme)
     allow_fragments = bool(allow_fragments)
     key = url, scheme, allow_fragments, type(url), type(scheme)
     cached = _parse_cache.get(key, None)
@@ -382,7 +393,8 @@ def unquote(s):
             append(item)
     return ''.join(res)
 
-def parse_qs(qs, keep_blank_values=0, strict_parsing=0, max_num_fields=None):
+def parse_qs(qs, keep_blank_values=0, strict_parsing=0, max_num_fields=None,
+             separator=None):
     """Parse a query given as a string argument.
 
         Arguments:
@@ -405,14 +417,23 @@ def parse_qs(qs, keep_blank_values=0, st
     """
     dict = {}
     for name, value in parse_qsl(qs, keep_blank_values, strict_parsing,
-                                 max_num_fields):
+                                 max_num_fields, separator):
         if name in dict:
             dict[name].append(value)
         else:
             dict[name] = [value]
     return dict
 
-def parse_qsl(qs, keep_blank_values=0, strict_parsing=0, max_num_fields=None):
+class _QueryStringSeparatorWarning(RuntimeWarning):
+    """Warning for using default `separator` in parse_qs or parse_qsl"""
+
+# The default "separator" for parse_qsl can be specified in a config file.
+# It's cached after first read.
+_QS_SEPARATOR_CONFIG_FILENAME = '@PKG_SYSCONFDIR@/python/urllib.cfg'
+_default_qs_separator = None
+
+def parse_qsl(qs, keep_blank_values=0, strict_parsing=0, max_num_fields=None,
+              separator=None):
     """Parse a query given as a string argument.
 
     Arguments:
@@ -434,15 +455,72 @@ def parse_qsl(qs, keep_blank_values=0, s
 
     Returns a list, as G-d intended.
     """
+
+    if (not separator or (not isinstance(separator, (str, bytes)))) and separator is not None:
+        raise ValueError("Separator must be of type string or bytes.")
+
+    # Used when both "&" and ";" act as separators. (Need a non-string value.)
+    _legacy = object()
+
+    if separator is None:
+        global _default_qs_separator
+        separator = _default_qs_separator
+        envvar_name = 'PYTHON_URLLIB_QS_SEPARATOR'
+        if separator is None:
+            # Set default separator from environment variable
+            separator = os.environ.get(envvar_name)
+            config_source = 'environment variable'
+        if separator is None:
+            # Set default separator from the configuration file
+            try:
+                file = open(_QS_SEPARATOR_CONFIG_FILENAME)
+            except EnvironmentError:
+                pass
+            else:
+                with file:
+                    import ConfigParser
+                    config = ConfigParser.ConfigParser()
+                    config.readfp(file)
+                    separator = config.get('parse_qs', envvar_name)
+                    _default_qs_separator = separator
+                config_source = _QS_SEPARATOR_CONFIG_FILENAME
+        if separator is None:
+            # The default is '&', but warn if not specified explicitly
+            if ';' in qs:
+                from warnings import warn
+                warn("The default separator of urlparse.parse_qsl and "
+                    + "parse_qs was changed to '&' to avoid a web cache "
+                    + "poisoning issue (CVE-2021-23336). "
+                    + "By default, semicolons no longer act as query field "
+                    + "separators. "
+                    + "See https://access.redhat.com/articles/5860431 for "
+                    + "more details.",
+                    _QueryStringSeparatorWarning, stacklevel=2)
+            separator = '&'
+        elif separator == 'legacy':
+            separator = _legacy
+        elif len(separator) != 1:
+            raise ValueError(
+                '{} (from {}) must contain '.format(envvar_name, config_source)
+                + '1 character, or "legacy". See '
+                + 'https://access.redhat.com/articles/5860431 for more details.'
+            )
+
     # If max_num_fields is defined then check that the number of fields
     # is less than max_num_fields. This prevents a memory exhaustion DOS
     # attack via post bodies with many fields.
     if max_num_fields is not None:
-        num_fields = 1 + qs.count('&') + qs.count(';')
+        if separator is _legacy:
+            num_fields = 1 + qs.count('&') + qs.count(';')
+        else:
+            num_fields = 1 + qs.count(separator)
         if max_num_fields < num_fields:
             raise ValueError('Max number of fields exceeded')
 
-    pairs = [s2 for s1 in qs.split('&') for s2 in s1.split(';')]
+    if separator is _legacy:
+        pairs = [s2 for s1 in qs.split('&') for s2 in s1.split(';')]
+    else:
+        pairs = [s1 for s1 in qs.split(separator)]
     r = []
     for name_value in pairs:
         if not name_value and not strict_parsing:
