$NetBSD: patch-src_scripts_install.py,v 1.1 2023/06/26 11:40:39 wiz Exp $

* install docs into share/doc/${PKGNAME}

--- src/scripts/install.py.orig	2022-01-29 07:12:00.830197062 +0000
+++ src/scripts/install.py
@@ -214,7 +214,7 @@ def main(args):
 
     if cfg['with_documentation']:
         target_doc_dir = os.path.join(prefix, cfg['docdir'],
-                                      'botan-%d.%d.%d' % (ver_major, ver_minor, ver_patch))
+                                      'botan%s-%d.%d.%d' % (cfg['program_suffix'] ,ver_major, ver_minor, ver_patch))
 
         shutil.rmtree(prepend_destdir(target_doc_dir), True)
         shutil.copytree(cfg['doc_output_dir'], prepend_destdir(target_doc_dir))
