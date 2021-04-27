$NetBSD: patch-scapy_consts.py,v 1.3 2021/04/27 21:53:11 gutteridge Exp $

Add DragonFly support.

--- scapy/consts.py.orig	2021-04-18 18:36:15.000000000 +0000
+++ scapy/consts.py
@@ -18,7 +18,8 @@ DARWIN = platform.startswith("darwin")
 SOLARIS = platform.startswith("sunos")
 WINDOWS = platform.startswith("win32")
 WINDOWS_XP = platform_lib.release() == "XP"
-BSD = DARWIN or FREEBSD or OPENBSD or NETBSD
+DRAGONFLY = platform.startswith("dragonfly")
+BSD = DARWIN or FREEBSD or OPENBSD or NETBSD or DRAGONFLY
 # See https://docs.python.org/3/library/platform.html#cross-platform
 IS_64BITS = maxsize > 2**32
 BIG_ENDIAN = byteorder == 'big'
