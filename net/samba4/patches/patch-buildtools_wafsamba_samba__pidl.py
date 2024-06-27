$NetBSD: patch-buildtools_wafsamba_samba__pidl.py,v 1.4 2024/06/27 09:50:27 adam Exp $

Do not set CPP, as it fails when using cwrappers.
If not provided, it will default to $CC -E (see pidl/idl.yp).

--- buildtools/wafsamba/samba_pidl.py.orig	2024-06-19 14:28:56.379517300 +0000
+++ buildtools/wafsamba/samba_pidl.py
@@ -81,9 +81,9 @@ def SAMBA_PIDL(bld, pname, source,
         else:
             cc = 'CC="%s"' % bld.CONFIG_GET("CC")
 
-    t = bld(rule=('cd ${PIDL_LAUNCH_DIR} && PERL_HASH_SEED=0 %s%s %s ${PERL} '
+    t = bld(rule=('cd ${PIDL_LAUNCH_DIR} && PERL_HASH_SEED=0 %s %s ${PERL} '
                   '${PIDL} --quiet ${OPTIONS} --outputdir ${OUTPUTDIR} -- "${IDLSRC}"' %
-                  (pidl_dev, cpp, cc)),
+                  (pidl_dev, cc)),
             ext_out    = '.c',
             before     = 'c',
             update_outputs = True,
