$NetBSD: patch-setup.py,v 1.1 2020/01/29 16:48:48 schmonz Exp $

Avoid setuptools_scm since tarball has no .git.

--- setup.py.orig	2019-02-26 22:03:32.000000000 +0000
+++ setup.py
@@ -113,10 +113,6 @@ if __name__ == '__main__':
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
@@ -126,7 +122,7 @@ if __name__ == '__main__':
                   % (mod.__prog__, mod.__prog__),
               ]
           },
-          setup_requires=['setuptools_scm',
+          setup_requires=[
                           'pytest-runner',
                           'pytest-cov',
                           'sphinx',
