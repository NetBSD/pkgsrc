$NetBSD: patch-kivy_clock.py,v 1.1 2026/10/28 05:09:43 wiz Exp $

Support NetBSD.

--- kivy/clock.py.orig	2026-10-27 17:57:38.893708086 +0000
+++ kivy/clock.py
@@ -531,7 +531,7 @@ try:
                     # 12: CLOCK_MONOTONIC_FAST (FreeBSD specific)
                     Logger.debug('clock.py: {{{:s}}} clock ID {:d}'.format(
                         platform, _clockid))
-                elif 'openbsd' in platform:
+                elif platform == 'openbsd' or platform.startswith('netbsd'):
                     _clockid = 3  # CLOCK_MONOTONIC
                 else:
                     _clockid = 1  # CLOCK_MONOTONIC
