$NetBSD: patch-docsrc_conf.py,v 1.2 2026/11/22 19:40:35 jnemeth Exp $

Replace external references to cyrussasl with actual links
to avoid web lookups while building.

--- docsrc/conf.py.orig	2026-11-16 20:54:41.000000000 +0000
+++ docsrc/conf.py
@@ -44,18 +44,10 @@ extensions = [
     'sphinx.ext.ifconfig',
     'sphinx.ext.mathjax',
     'sphinx.ext.todo',
-    'sphinx.ext.intersphinx',
 ]
 
 extensions.append('sphinxlocal.roles.cyrusman')
 extensions.append('sphinxlocal.sitemap')
-
-# We publish master branch at /dev
-# Other branches are available at multiple locations (3.12 is at 3.12 and stable and /).
-# Supply all webroots that this set of docs is available at.
-sitemap_website = ["https://www.cyrusimap.org/dev/"]
-
-intersphinx_mapping = {'cyrussasl': ('https://www.cyrusimap.org/sasl', None)}
 
 mathjax_path = 'https://cdn.mathjax.org/mathjax/latest/MathJax.js'
 
