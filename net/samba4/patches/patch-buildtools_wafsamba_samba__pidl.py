$NetBSD: patch-buildtools_wafsamba_samba__pidl.py,v 1.1 2018/12/22 01:13:52 adam Exp $

Do not set CPP, as it fails when using cwrappers.
If not provided, it will default to $CC -E (see pidl/idl.yp).

--- buildtools/wafsamba/samba_pidl.py.orig	2018-12-21 18:12:39.000000000 +0000
+++ buildtools/wafsamba/samba_pidl.py
@@ -76,7 +76,7 @@ def SAMBA_PIDL(bld, pname, source,
         else:
             cc = 'CC="%s"' % bld.CONFIG_GET("CC")
 
-    t = bld(rule='cd .. && %s %s ${PERL} "${PIDL}" --quiet ${OPTIONS} --outputdir ${OUTPUTDIR} -- "${SRC[0].abspath(env)}"' % (cpp, cc),
+    t = bld(rule='cd .. && %s ${PERL} "${PIDL}" --quiet ${OPTIONS} --outputdir ${OUTPUTDIR} -- "${SRC[0].abspath(env)}"' % cc,
             ext_out    = '.c',
             before     = 'cc',
             update_outputs = True,
