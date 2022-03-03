$NetBSD: patch-Lib_test_test__urlparse.py,v 1.1.4.1 2022/03/03 19:33:58 bsiegert Exp $

Fix CVE-2021-23336: Add `separator` argument to parse_qs; warn with default
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00359-CVE-2021-23336.patch

Fix CVE-2022-0391: urlparse does not sanitize URLs containing ASCII newline and tabs
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/40dd05e5d77dbfa81777c9f84b704bc2239bf710/f/00377-CVE-2022-0391.patch

--- Lib/test/test_urlparse.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/test/test_urlparse.py
@@ -3,6 +3,12 @@ import sys
 import unicodedata
 import unittest
 import urlparse
+from test.support import EnvironmentVarGuard
+from warnings import catch_warnings, filterwarnings
+import tempfile
+import contextlib
+import os.path
+import shutil
 
 RFC1808_BASE = "http://a/b/c/d;p?q#f"
 RFC2396_BASE = "http://a/b/c/d;p?q"
@@ -24,16 +30,29 @@ parse_qsl_test_cases = [
     ("&a=b", [('a', 'b')]),
     ("a=a+b&b=b+c", [('a', 'a b'), ('b', 'b c')]),
     ("a=1&a=2", [('a', '1'), ('a', '2')]),
+]
+
+parse_qsl_test_cases_semicolon = [
     (";", []),
     (";;", []),
     (";a=b", [('a', 'b')]),
     ("a=a+b;b=b+c", [('a', 'a b'), ('b', 'b c')]),
     ("a=1;a=2", [('a', '1'), ('a', '2')]),
-    (b";", []),
-    (b";;", []),
-    (b";a=b", [(b'a', b'b')]),
-    (b"a=a+b;b=b+c", [(b'a', b'a b'), (b'b', b'b c')]),
-    (b"a=1;a=2", [(b'a', b'1'), (b'a', b'2')]),
+]
+
+parse_qsl_test_cases_legacy = [
+    ("a=1;a=2&a=3", [('a', '1'), ('a', '2'), ('a', '3')]),
+    ("a=1;b=2&c=3", [('a', '1'), ('b', '2'), ('c', '3')]),
+    ("a=1&b=2&c=3;", [('a', '1'), ('b', '2'), ('c', '3')]),
+]
+
+parse_qsl_test_cases_warn = [
+    (";a=b", [(';a', 'b')]),
+    ("a=a+b;b=b+c", [('a', 'a b;b=b c')]),
+    (b";a=b", [(b';a', b'b')]),
+    (b"a=a+b;b=b+c", [(b'a', b'a b;b=b c')]),
+    ("a=1;a=2&a=3", [('a', '1;a=2'), ('a', '3')]),
+    (b"a=1;a=2&a=3", [(b'a', b'1;a=2'), (b'a', b'3')]),
 ]
 
 parse_qs_test_cases = [
@@ -57,6 +76,9 @@ parse_qs_test_cases = [
     (b"&a=b", {b'a': [b'b']}),
     (b"a=a+b&b=b+c", {b'a': [b'a b'], b'b': [b'b c']}),
     (b"a=1&a=2", {b'a': [b'1', b'2']}),
+]
+
+parse_qs_test_cases_semicolon = [
     (";", {}),
     (";;", {}),
     (";a=b", {'a': ['b']}),
@@ -69,6 +91,24 @@ parse_qs_test_cases = [
     (b"a=1;a=2", {b'a': [b'1', b'2']}),
 ]
 
+parse_qs_test_cases_legacy = [
+    ("a=1;a=2&a=3", {'a': ['1', '2', '3']}),
+    ("a=1;b=2&c=3", {'a': ['1'], 'b': ['2'], 'c': ['3']}),
+    ("a=1&b=2&c=3;", {'a': ['1'], 'b': ['2'], 'c': ['3']}),
+    (b"a=1;a=2&a=3", {b'a': [b'1', b'2', b'3']}),
+    (b"a=1;b=2&c=3", {b'a': [b'1'], b'b': [b'2'], b'c': [b'3']}),
+    (b"a=1&b=2&c=3;", {b'a': [b'1'], b'b': [b'2'], b'c': [b'3']}),
+]
+
+parse_qs_test_cases_warn = [
+    (";a=b", {';a': ['b']}),
+    ("a=a+b;b=b+c", {'a': ['a b;b=b c']}),
+    (b";a=b", {b';a': [b'b']}),
+    (b"a=a+b;b=b+c", {b'a':[ b'a b;b=b c']}),
+    ("a=1;a=2&a=3", {'a': ['1;a=2', '3']}),
+    (b"a=1;a=2&a=3", {b'a': [b'1;a=2', b'3']}),
+]
+
 class UrlParseTestCase(unittest.TestCase):
 
     def checkRoundtrips(self, url, parsed, split):
@@ -141,6 +181,40 @@ class UrlParseTestCase(unittest.TestCase
             self.assertEqual(result, expect_without_blanks,
                     "Error parsing %r" % orig)
 
+    def test_qs_default_warn(self):
+        for orig, expect in parse_qs_test_cases_warn:
+            with catch_warnings(record=True) as w:
+                filterwarnings(action='always',
+                                        category=urlparse._QueryStringSeparatorWarning)
+                result = urlparse.parse_qs(orig, keep_blank_values=True)
+                self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 1)
+            self.assertEqual(w[0].category, urlparse._QueryStringSeparatorWarning)
+
+    def test_qsl_default_warn(self):
+        for orig, expect in parse_qsl_test_cases_warn:
+            with catch_warnings(record=True) as w:
+                filterwarnings(action='always',
+                               category=urlparse._QueryStringSeparatorWarning)
+                result = urlparse.parse_qsl(orig, keep_blank_values=True)
+                self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 1)
+            self.assertEqual(w[0].category, urlparse._QueryStringSeparatorWarning)
+
+    def test_default_qs_no_warnings(self):
+        for orig, expect in parse_qs_test_cases:
+            with catch_warnings(record=True) as w:
+                result = urlparse.parse_qs(orig, keep_blank_values=True)
+                self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+
+    def test_default_qsl_no_warnings(self):
+        for orig, expect in parse_qsl_test_cases:
+            with catch_warnings(record=True) as w:
+                result = urlparse.parse_qsl(orig, keep_blank_values=True)
+                self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+
     def test_roundtrips(self):
         testcases = [
             ('file:///tmp/junk.txt',
@@ -544,6 +618,55 @@ class UrlParseTestCase(unittest.TestCase
         self.assertEqual(p1.path, '863-1234')
         self.assertEqual(p1.params, 'phone-context=+1-914-555')
 
+    def test_urlsplit_remove_unsafe_bytes(self):
+        # Remove ASCII tabs and newlines from input, for http common case scenario.
+        url = "h\nttp://www.python\n.org\t/java\nscript:\talert('msg\r\n')/?query\n=\tsomething#frag\nment"
+        p = urlparse.urlsplit(url)
+        self.assertEqual(p.scheme, "http")
+        self.assertEqual(p.netloc, "www.python.org")
+        self.assertEqual(p.path, "/javascript:alert('msg')/")
+        self.assertEqual(p.query, "query=something")
+        self.assertEqual(p.fragment, "fragment")
+        self.assertEqual(p.username, None)
+        self.assertEqual(p.password, None)
+        self.assertEqual(p.hostname, "www.python.org")
+        self.assertEqual(p.port, None)
+        self.assertEqual(p.geturl(), "http://www.python.org/javascript:alert('msg')/?query=something#fragment")
+
+        # Remove ASCII tabs and newlines from input as bytes, for http common case scenario.
+        url = b"h\nttp://www.python\n.org\t/java\nscript:\talert('msg\r\n')/?query\n=\tsomething#frag\nment"
+        p = urlparse.urlsplit(url)
+        self.assertEqual(p.scheme, b"http")
+        self.assertEqual(p.netloc, b"www.python.org")
+        self.assertEqual(p.path, b"/javascript:alert('msg')/")
+        self.assertEqual(p.query, b"query=something")
+        self.assertEqual(p.fragment, b"fragment")
+        self.assertEqual(p.username, None)
+        self.assertEqual(p.password, None)
+        self.assertEqual(p.hostname, b"www.python.org")
+        self.assertEqual(p.port, None)
+        self.assertEqual(p.geturl(), b"http://www.python.org/javascript:alert('msg')/?query=something#fragment")
+
+        # any scheme
+        url = "x-new-scheme\t://www.python\n.org\t/java\nscript:\talert('msg\r\n')/?query\n=\tsomething#frag\nment"
+        p = urlparse.urlsplit(url)
+        self.assertEqual(p.geturl(), "x-new-scheme://www.python.org/javascript:alert('msg')/?query=something#fragment")
+
+        # Remove ASCII tabs and newlines from input as bytes, any scheme.
+        url = b"x-new-scheme\t://www.python\n.org\t/java\nscript:\talert('msg\r\n')/?query\n=\tsomething#frag\nment"
+        p = urlparse.urlsplit(url)
+        self.assertEqual(p.geturl(), b"x-new-scheme://www.python.org/javascript:alert('msg')/?query=something#fragment")
+
+        # Unsafe bytes is not returned from urlparse cache.
+        # scheme is stored after parsing, sending an scheme with unsafe bytes *will not* return an unsafe scheme
+        url = "https://www.python\n.org\t/java\nscript:\talert('msg\r\n')/?query\n=\tsomething#frag\nment"
+        scheme = "htt\nps"
+        for _ in range(2):
+            p = urlparse.urlsplit(url, scheme=scheme)
+            self.assertEqual(p.scheme, "https")
+            self.assertEqual(p.geturl(), "https://www.python.org/javascript:alert('msg')/?query=something#fragment")
+
+
 
     def test_attributes_bad_port(self):
         """Check handling of non-integer ports."""
@@ -626,6 +749,132 @@ class UrlParseTestCase(unittest.TestCase
         self.assertEqual(urlparse.urlparse("http://www.python.org:80"),
                 ('http','www.python.org:80','','','',''))
 
+    def test_parse_qs_separator_bytes(self):
+        expected = {b'a': [b'1'], b'b': [b'2']}
+
+        result = urlparse.parse_qs(b'a=1;b=2', separator=b';')
+        self.assertEqual(result, expected)
+        result = urlparse.parse_qs(b'a=1;b=2', separator=';')
+        self.assertEqual(result, expected)
+        result = urlparse.parse_qs('a=1;b=2', separator=';')
+        self.assertEqual(result, {'a': ['1'], 'b': ['2']})
+
+    @contextlib.contextmanager
+    def _qsl_sep_config(self, sep):
+        """Context for the given parse_qsl default separator configured in config file"""
+        old_filename = urlparse._QS_SEPARATOR_CONFIG_FILENAME
+        urlparse._default_qs_separator = None
+        try:
+            tmpdirname = tempfile.mkdtemp()
+            filename = os.path.join(tmpdirname, 'conf.cfg')
+            with open(filename, 'w') as file:
+                file.write('[parse_qs]\n')
+                file.write('PYTHON_URLLIB_QS_SEPARATOR = {}'.format(sep))
+            urlparse._QS_SEPARATOR_CONFIG_FILENAME = filename
+            yield
+        finally:
+            urlparse._QS_SEPARATOR_CONFIG_FILENAME = old_filename
+            urlparse._default_qs_separator = None
+            shutil.rmtree(tmpdirname)
+
+    def test_parse_qs_separator_semicolon(self):
+        for orig, expect in parse_qs_test_cases_semicolon:
+            result = urlparse.parse_qs(orig, separator=';')
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            with EnvironmentVarGuard() as environ, catch_warnings(record=True) as w:
+                environ['PYTHON_URLLIB_QS_SEPARATOR'] = ';'
+                result = urlparse.parse_qs(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+            with self._qsl_sep_config(';'), catch_warnings(record=True) as w:
+                result = urlparse.parse_qs(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+
+    def test_parse_qsl_separator_semicolon(self):
+        for orig, expect in parse_qsl_test_cases_semicolon:
+            result = urlparse.parse_qsl(orig, separator=';')
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            with EnvironmentVarGuard() as environ, catch_warnings(record=True) as w:
+                environ['PYTHON_URLLIB_QS_SEPARATOR'] = ';'
+                result = urlparse.parse_qsl(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+            with self._qsl_sep_config(';'), catch_warnings(record=True) as w:
+                result = urlparse.parse_qsl(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+
+    def test_parse_qs_separator_legacy(self):
+        for orig, expect in parse_qs_test_cases_legacy:
+            with EnvironmentVarGuard() as environ, catch_warnings(record=True) as w:
+                environ['PYTHON_URLLIB_QS_SEPARATOR'] = 'legacy'
+                result = urlparse.parse_qs(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+            with self._qsl_sep_config('legacy'), catch_warnings(record=True) as w:
+                result = urlparse.parse_qs(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+
+    def test_parse_qsl_separator_legacy(self):
+        for orig, expect in parse_qsl_test_cases_legacy:
+            with EnvironmentVarGuard() as environ, catch_warnings(record=True) as w:
+                environ['PYTHON_URLLIB_QS_SEPARATOR'] = 'legacy'
+                result = urlparse.parse_qsl(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+            with self._qsl_sep_config('legacy'), catch_warnings(record=True) as w:
+                result = urlparse.parse_qsl(orig)
+            self.assertEqual(result, expect, "Error parsing %r" % orig)
+            self.assertEqual(len(w), 0)
+
+    def test_parse_qs_separator_bad_value_env_or_config(self):
+        for bad_sep in '', 'abc', 'safe', '&;', 'SEP':
+            with EnvironmentVarGuard() as environ, catch_warnings(record=True) as w:
+                environ['PYTHON_URLLIB_QS_SEPARATOR'] = bad_sep
+                with self.assertRaises(ValueError):
+                    urlparse.parse_qsl('a=1;b=2')
+            with self._qsl_sep_config('bad_sep'), catch_warnings(record=True) as w:
+                with self.assertRaises(ValueError):
+                    urlparse.parse_qsl('a=1;b=2')
+
+    def test_parse_qs_separator_bad_value_arg(self):
+        for bad_sep in True, {}, '':
+            with self.assertRaises(ValueError):
+                urlparse.parse_qsl('a=1;b=2', separator=bad_sep)
+
+    def test_parse_qs_separator_num_fields(self):
+        for qs, sep in (
+            ('a&b&c', '&'),
+            ('a;b;c', ';'),
+            ('a&b;c', 'legacy'),
+        ):
+            with EnvironmentVarGuard() as environ, catch_warnings(record=True) as w:
+                if sep != 'legacy':
+                    with self.assertRaises(ValueError):
+                        urlparse.parse_qsl(qs, separator=sep, max_num_fields=2)
+                if sep:
+                    environ['PYTHON_URLLIB_QS_SEPARATOR'] = sep
+                with self.assertRaises(ValueError):
+                    urlparse.parse_qsl(qs, max_num_fields=2)
+
+    def test_parse_qs_separator_priority(self):
+        # env variable trumps config file
+        with self._qsl_sep_config('~'), EnvironmentVarGuard() as environ:
+            environ['PYTHON_URLLIB_QS_SEPARATOR'] = '!'
+            result = urlparse.parse_qs('a=1!b=2~c=3')
+            self.assertEqual(result, {'a': ['1'], 'b': ['2~c=3']})
+        # argument trumps config file
+        with self._qsl_sep_config('~'):
+            result = urlparse.parse_qs('a=1$b=2~c=3', separator='$')
+            self.assertEqual(result, {'a': ['1'], 'b': ['2~c=3']})
+        # argument trumps env variable
+        with EnvironmentVarGuard() as environ:
+            environ['PYTHON_URLLIB_QS_SEPARATOR'] = '~'
+            result = urlparse.parse_qs('a=1$b=2~c=3', separator='$')
+            self.assertEqual(result, {'a': ['1'], 'b': ['2~c=3']})
+
     def test_urlsplit_normalization(self):
         # Certain characters should never occur in the netloc,
         # including under normalization.
