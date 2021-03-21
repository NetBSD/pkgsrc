$NetBSD: patch-scapy_consts.py,v 1.2 2021/03/21 19:50:54 gutteridge Exp $

Add DragonFly support.

--- scapy/consts.py.orig	2020-09-02 11:26:21.000000000 +0000
+++ scapy/consts.py
@@ -14,7 +14,8 @@ DARWIN = platform.startswith("darwin")
 SOLARIS = platform.startswith("sunos")
 WINDOWS = platform.startswith("win32")
 WINDOWS_XP = platform_lib.release() == "XP"
-BSD = DARWIN or FREEBSD or OPENBSD or NETBSD
+DRAGONFLY = platform.startswith("dragonfly")
+BSD = DARWIN or FREEBSD or OPENBSD or NETBSD or DRAGONFLY
 # See https://docs.python.org/3/library/platform.html#cross-platform
 IS_64BITS = maxsize > 2**32
 # LOOPBACK_NAME moved to conf.loopback_name
