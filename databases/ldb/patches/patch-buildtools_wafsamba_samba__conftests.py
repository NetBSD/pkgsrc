$NetBSD: patch-buildtools_wafsamba_samba__conftests.py,v 1.2 2019/11/10 16:58:06 adam Exp $

Ensure defines are strings to avoid assertion failure, some
returned values are unicode.

--- buildtools/wafsamba/samba_conftests.py.orig	2019-03-21 10:12:32.000000000 +0000
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
 
     if conf.CHECK_CODE('if (sizeof(off_t) < 8) return 1',
                        define,
