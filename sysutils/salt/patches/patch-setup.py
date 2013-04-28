$NetBSD: patch-setup.py,v 1.3 2013/04/28 09:46:25 imil Exp $

* Remove unused example_path and template_path;
* Set etc_path to the directory where configfiles will be
  installed, which is PREFIX/share/examples, not /etc or
  PKG_SYSCONFDIR.  The files are copied to PKG_SYSCONFDIR
  via the CONFIG_FILES setting in the pkgsrc Makefile.
* Install man pages in PKGMANDIR, not PREFIX/share/man.

--- setup.py.orig	2013-03-29 00:06:49.000000000 +0000
+++ setup.py
@@ -151,13 +151,15 @@ DESC = ('Portable, distributed, remote e
         'configuration management system')
 mod_path = os.path.join(get_python_lib(), 'salt/modules')
 doc_path = os.path.join(PREFIX, 'share/doc', NAME + '-' + VER)
-example_path = os.path.join(doc_path, 'examples')
-template_path = os.path.join(example_path, 'templates')
 
-if 'SYSCONFDIR' in os.environ:
-    etc_path = os.environ['SYSCONFDIR']
+# For pkgsrc:
+# * Do not define example_path, template_path, or etc_path; they are not used.
+# * man_path should be set to PKGMANDIR, defaulting to PREFIX/share/man.
+#
+if 'PKGMANDIR' in os.environ:
+    man_path = os.environ['PKGMANDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    man_path = os.path.join(os.path.dirname(PREFIX), 'share/man')
 
 with open(salt_reqs) as f:
     lines = f.read().split('\n')
@@ -210,7 +212,7 @@ setup_kwargs = {'name': NAME,
                              'salt.utils',
                              ],
                 'package_data': {'salt.modules': ['rh_ip/*.jinja']},
-                'data_files': [('share/man/man1',
+                'data_files': [(os.path.join(man_path, 'man1'),
                                 ['doc/man/salt-master.1',
                                  'doc/man/salt-key.1',
                                  'doc/man/salt.1',
@@ -220,7 +222,8 @@ setup_kwargs = {'name': NAME,
                                  'doc/man/salt-run.1',
                                  'doc/man/salt-minion.1',
                                  ]),
-                               ('share/man/man7', ['doc/man/salt.7']),
+                               (os.path.join(man_path, 'man7'),
+                                ['doc/man/salt.7']),
                                ],
                 # Required for esky builds
                 'install_requires': requirements,
