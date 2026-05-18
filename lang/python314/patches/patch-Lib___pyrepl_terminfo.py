$NetBSD: patch-Lib___pyrepl_terminfo.py,v 1.1 2026/05/18 21:23:27 wiz Exp $

Use C interface for getting information out of libterminfo on NetBSD.
Fall back to ansi for tmux-direct.
https://github.com/python/cpython/issues/140296

--- Lib/_pyrepl/terminfo.py.orig	2026-05-10 10:21:34.000000000 +0000
+++ Lib/_pyrepl/terminfo.py
@@ -1,6 +1,8 @@ from dataclasses import dataclass, field
 """Pure Python curses-like terminal capability queries."""
 
 from dataclasses import dataclass, field
+import ctypes
+import ctypes.util
 import errno
 import os
 from pathlib import Path
@@ -130,6 +132,47 @@ def _validate_terminal_name_or_raise(terminal_name: st
         raise ValueError("`terminal_name` cannot contain path separators")
 
 
+def _load_from_system_terminfo(terminal_name: str) -> dict[str, bytes] | None:
+    """Try to load terminal capabilities via the system terminfo(3) library.
+
+    Returns None if the library is unavailable or the terminal is unknown.
+    """
+    for libname in ("terminfo", "tinfo", "curses", "ncurses"):
+        soname = ctypes.util.find_library(libname)
+        if soname is None:
+            continue
+        try:
+            lib = ctypes.CDLL(soname)
+        except OSError:
+            continue
+        try:
+            lib.setupterm.restype = ctypes.c_int
+            lib.setupterm.argtypes = [
+                ctypes.c_char_p, ctypes.c_int, ctypes.POINTER(ctypes.c_int)
+            ]
+            # Use c_void_p to avoid auto-dereferencing (char*)-1
+            # that tigetstr returns for invalid capabilities.
+            lib.tigetstr.restype = ctypes.c_void_p
+            lib.tigetstr.argtypes = [ctypes.c_char_p]
+        except AttributeError:
+            continue
+        errret = ctypes.c_int(0)
+        ret = lib.setupterm(
+            terminal_name.encode(), 1, ctypes.byref(errret)
+        )
+        if ret != 0 or errret.value != 1:
+            return None
+        capabilities: dict[str, bytes] = {}
+        invalid = ctypes.c_void_p(-1).value
+        for cap in _STRING_NAMES:
+            addr = lib.tigetstr(cap.encode())
+            if addr is None or addr == invalid:
+                continue
+            capabilities[cap] = ctypes.string_at(addr)
+        return capabilities
+    return None
+
+
 def _read_terminfo_file(terminal_name: str) -> bytes:
     """Find and read terminfo file for given terminal name.
 
@@ -307,6 +350,7 @@ _TERM_ALIASES = {
     "screen-256color": "ansi",
     "tmux": "ansi",
     "tmux-256color": "ansi",
+    "tmux-direct": "ansi",
     "vt100": "ansi",
     "vt220": "ansi",
     "rxvt": "ansi",
@@ -331,8 +375,9 @@ class TermInfo:
         - ncurses/tinfo/lib_setup.c:TINFO_SETUP_TERM()
 
         This version first attempts to read terminfo database files like ncurses,
-        then, if `fallback` is True, falls back to hardcoded capabilities for
-        common terminal types.
+        then tries finding information from terminfo via ctypes, and finally, if
+        `fallback` is True, falls back to hardcoded capabilities for common terminal
+        types.
         """
         # If termstr is None or empty, try to get from environment
         if not self.terminal_name:
@@ -344,6 +389,11 @@ class TermInfo:
         try:
             self._parse_terminfo_file(self.terminal_name)
         except (OSError, ValueError):
+            caps = _load_from_system_terminfo(self.terminal_name)
+            if caps is not None:
+                self._capabilities = caps
+                return
+
             if not self.fallback:
                 raise
 
