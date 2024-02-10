$NetBSD: patch-setup.py,v 1.1 2024/02/10 07:10:42 adam Exp $

Install man in Makefile.

--- setup.py.orig	2024-02-10 07:06:07.491902451 +0000
+++ setup.py
@@ -29,7 +29,6 @@ def main():
         packages=['CloudFlare', 'CloudFlare/tests', 'cli4', 'examples'],
         test_suite="CloudFlare.tests",
         include_package_data=True,
-        data_files=[('share/man/man1', ['cli4/cli4.1'])],
         install_requires=['requests', 'pyyaml', 'jsonlines'],
         keywords='cloudflare',
         entry_points={
