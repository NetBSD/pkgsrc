$NetBSD: patch-setup.py,v 1.1 2022/01/25 18:30:25 wiz Exp $

--- setup.py.orig	2021-09-27 10:42:46.747815100 +0000
+++ setup.py
@@ -13,7 +13,7 @@ package_data = \
 {'': ['*']}
 
 install_requires = \
-['aiofiles>=0.6.0,<0.7.0',
+['aiofiles>=0.6.0',
  'aiohttp-socks>=0.6.0,<0.7.0',
  'aiohttp>=3.7.4,<4.0.0',
  'future>=0.18.2,<0.19.0',
