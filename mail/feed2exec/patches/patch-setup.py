$NetBSD: patch-setup.py,v 1.2 2020/10/07 19:46:53 schmonz Exp $

Avoid setuptools_scm since tarball has no .git.

--- setup.py.orig	2020-10-06 18:35:43.000000000 +0000
+++ setup.py
@@ -126,10 +126,6 @@ if __name__ == '__main__':
           long_description=sphinx2rst('README.rst'),
           license=mod.__license_short__,
           url=mod.__website__,
-          use_scm_version={
-              'write_to': '%s/_version.py'
-              % mod.__prog__,
-          },
           packages=packages,
           package_data=package_data,
           entry_points={
@@ -140,7 +136,6 @@ if __name__ == '__main__':
               ]
           },
           setup_requires=[
-              'setuptools_scm',
               'sphinx',
           ],
           install_requires=requires,
