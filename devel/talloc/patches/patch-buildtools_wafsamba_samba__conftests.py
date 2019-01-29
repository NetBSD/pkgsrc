$NetBSD: patch-buildtools_wafsamba_samba__conftests.py,v 1.3 2019/01/29 23:40:37 jperkin Exp $

Ensure defines are strings to avoid assertion failure, some
returned values are unicode.

--- buildtools/wafsamba/samba_conftests.py.orig	2019-01-14 22:24:44.000000000 +0000
+++ buildtools/wafsamba/samba_conftests.py
@@ -97,9 +97,9 @@ def CHECK_LARGEFILE(conf, define='HAVE_L
                 if flag[:2] == "-D":
                     flag_split = flag[2:].split('=')
                     if len(flag_split) == 1:
-                        conf.DEFINE(flag_split[0], '1')
+                        conf.DEFINE(str(flag_split[0]), '1')
                     else:
-                        conf.DEFINE(flag_split[0], flag_split[1])
+                        conf.DEFINE(str(flag_split[0]), str(flag_split[1]))
 
     if conf.CHECK_CODE('return !(sizeof(off_t) >= 8)',
                        define,
