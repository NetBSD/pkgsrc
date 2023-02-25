$NetBSD: patch-setup.py,v 1.1 2023/02/25 14:01:42 gdt Exp $

Patch out installing site-packages/tests because it collides with other
packages that also should not install to that name.

https://github.com/sdispater/cachy/issues/30

--- setup.py.orig	1970-01-01 00:00:00.000000000 +0000
+++ setup.py
@@ -6,8 +6,7 @@ packages = \
  'cachy.contracts',
  'cachy.serializers',
  'cachy.stores',
- 'tests',
- 'tests.stores']
+]
 
 package_data = \
 {'': ['*']}
