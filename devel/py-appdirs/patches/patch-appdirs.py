$NetBSD: patch-appdirs.py,v 1.1 2020/07/21 10:15:39 wiz Exp $

Only use ASCII, to avoid with python36:

Traceback (most recent call last):
  File "setup.py", line 25, in <module>
    for line in read("appdirs.py").splitlines():
  File "setup.py", line 19, in read
    out = "\n" + inf.read().replace("\r\n", "\n")
  File "/usr/pkg/lib/python3.6/encodings/ascii.py", line 26, in decode
    return codecs.ascii_decode(input, self.errors)[0]
UnicodeDecodeError: 'ascii' codec can't decode byte 0xc8 in position 129: ordinal not in range(128)

--- appdirs.py.orig	2020-05-10 23:54:42.000000000 +0000
+++ appdirs.py
@@ -1,7 +1,7 @@
 #!/usr/bin/env python
 # -*- coding: utf-8 -*-
 # Copyright (c) 2005-2010 ActiveState Software Inc.
-# Copyright (c) 2013 Eddy Petrișor
+# Copyright (c) 2013 Eddy Petrisor
 
 """Utilities for determining application-specific dirs.
 
