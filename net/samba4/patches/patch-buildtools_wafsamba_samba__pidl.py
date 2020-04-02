$NetBSD: patch-buildtools_wafsamba_samba__pidl.py,v 1.3 2020/04/02 11:21:42 adam Exp $

Do not set CPP, as it fails when using cwrappers.
If not provided, it will default to $CC -E (see pidl/idl.yp).

--- buildtools/wafsamba/samba_pidl.py.orig	2020-01-31 10:25:36.000000000 +0000
+++ buildtools/wafsamba/samba_pidl.py
@@ -80,7 +80,7 @@ def SAMBA_PIDL(bld, pname, source,
         else:
             cc = 'CC="%s"' % bld.CONFIG_GET("CC")
 
-    t = bld(rule='cd ${PIDL_LAUNCH_DIR} && %s%s %s ${PERL} ${PIDL} --quiet ${OPTIONS} --outputdir ${OUTPUTDIR} -- "${IDLSRC}"' % (pidl_dev, cpp, cc),
+    t = bld(rule='cd ${PIDL_LAUNCH_DIR} && %s %s ${PERL} ${PIDL} --quiet ${OPTIONS} --outputdir ${OUTPUTDIR} -- "${IDLSRC}"' % (pidl_dev, cc),
             ext_out    = '.c',
             before     = 'c',
             update_outputs = True,
