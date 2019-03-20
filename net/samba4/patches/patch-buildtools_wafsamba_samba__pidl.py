$NetBSD: patch-buildtools_wafsamba_samba__pidl.py,v 1.2 2019/03/20 19:09:10 adam Exp $

Do not set CPP, as it fails when using cwrappers.
If not provided, it will default to $CC -E (see pidl/idl.yp).

--- buildtools/wafsamba/samba_pidl.py.orig	2019-01-15 10:07:00.000000000 +0000
+++ buildtools/wafsamba/samba_pidl.py
@@ -76,7 +76,7 @@ def SAMBA_PIDL(bld, pname, source,
         else:
             cc = 'CC="%s"' % bld.CONFIG_GET("CC")
 
-    t = bld(rule='cd ${PIDL_LAUNCH_DIR} && %s %s ${PERL} ${PIDL} --quiet ${OPTIONS} --outputdir ${OUTPUTDIR} -- "${IDLSRC}"' % (cpp, cc),
+    t = bld(rule='cd ${PIDL_LAUNCH_DIR} && %s ${PERL} ${PIDL} --quiet ${OPTIONS} --outputdir ${OUTPUTDIR} -- "${IDLSRC}"' % cc,
             ext_out    = '.c',
             before     = 'c',
             update_outputs = True,
