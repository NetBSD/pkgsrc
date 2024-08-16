$NetBSD: patch-python_mach_mach_main.py,v 1.1 2024/08/16 10:20:40 nia Exp $

These python libraries were moved out of "collections" and their
original locations were deprecated.

--- python/mach/mach/main.py.orig	2024-08-16 10:13:11.002052040 +0000
+++ python/mach/mach/main.py
@@ -16,7 +16,7 @@ import os
 import sys
 import traceback
 import uuid
-from collections import Iterable
+from collections.abc import Iterable
 
 from six import string_types
 
