$NetBSD: patch-scapy_consts.py,v 1.1 2019/11/04 05:48:26 gutteridge Exp $

Add DragonFly support.

--- scapy/consts.py.orig	2019-10-22 16:33:00.860254151 +0000
+++ scapy/consts.py
@@ -15,7 +15,8 @@ DARWIN = platform.startswith("darwin")
 SOLARIS = platform.startswith("sunos")
 WINDOWS = platform.startswith("win32")
 WINDOWS_XP = platform_lib.release() == "XP"
-BSD = DARWIN or FREEBSD or OPENBSD or NETBSD
+DRAGONFLY = platform.startswith("dragonfly")
+BSD = DARWIN or FREEBSD or OPENBSD or NETBSD or DRAGONFLY
 # See https://docs.python.org/3/library/platform.html#cross-platform
 IS_64BITS = maxsize > 2**32
 
