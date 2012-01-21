$NetBSD: patch-setup.py,v 1.1 2012/01/21 20:26:58 apb Exp $

* Remove unused example_path and template_path;
* Set etc_path to the directory where configfiles will be
  installed, which is PREFIX/share/examples, not /etc or
  PKG_SYSCONFDIR.  The files are copied to PKG_SYSCONFDIR
  via the CONFIG_FILES setting in the pkgsrc Makefile.
* Install man pages in PKGMANDIR, not PREFIX/share/man.

--- setup.py.orig	2012-01-15 22:10:25.000000000 +0000
+++ setup.py
@@ -47,13 +47,14 @@ DESC = ('Portable, distributed, remote e
         'configuration management system')
 mod_path = os.path.join(get_python_lib(), 'salt/modules')
 doc_path = os.path.join(PREFIX, 'share/doc', NAME + '-' + VER)
-example_path = os.path.join(doc_path, 'examples')
-template_path = os.path.join(example_path, 'templates')
 
-if 'SYSCONFDIR' in os.environ:
-    etc_path = os.environ['SYSCONFDIR']
+# for pkgsrc, install etc files in PREFIX/share/examples
+etc_path = os.path.join(PREFIX, 'share/examples')
+
+if 'PKGMANDIR' in os.environ:
+    man_path = os.environ['PKGMANDIR']
 else:
-    etc_path = os.path.join(os.path.dirname(PREFIX), 'etc')
+    man_path = os.path.join(os.path.dirname(PREFIX), 'share/man')
 
 # take care of extension modules.
 if have_cython:
@@ -125,7 +126,7 @@ setup(
                     ['conf/master',
                      'conf/minion',
                     ]),
-                ('share/man/man1',
+                (os.path.join(man_path, 'man1'),
                     ['doc/man/salt-master.1',
                      'doc/man/salt-key.1',
                      'doc/man/salt.1',
@@ -135,7 +136,7 @@ setup(
                      'doc/man/salt-run.1',
                      'doc/man/salt-minion.1',
                     ]),
-                ('share/man/man7',
+                (os.path.join(man_path, 'man7'),
                     ['doc/man/salt.7',
                     ]),
                 (mod_path,
