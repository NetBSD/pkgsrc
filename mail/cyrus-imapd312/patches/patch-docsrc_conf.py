$NetBSD: patch-docsrc_conf.py,v 1.1 2026/03/09 03:16:44 jnemeth Exp $

Replace external references to cyrussasl with actual links
to avoid web lookups while building.

--- docsrc/conf.py.orig	2026-01-19 06:36:47.207902527 +0000
+++ docsrc/conf.py
@@ -44,7 +44,6 @@ extensions = [
     'sphinx.ext.ifconfig',
     'sphinx.ext.mathjax',
     'sphinx.ext.todo',
-    'sphinx.ext.intersphinx',
 ]
 
 extensions.append('sphinxlocal.roles.cyrusman')
@@ -54,13 +53,6 @@ gitstamp_fmt = "%b %d %Y"
 
 extensions.append('sphinxlocal.sitemap')
 
-# We publish master branch at /dev
-# Other branches are available at multiple locations (3.12 is at 3.12 and stable and /).
-# Supply all webroots that this set of docs is available at.
-sitemap_website = ["https://www.cyrusimap.org/dev/"]
-
-intersphinx_mapping = {'cyrussasl': ('https://www.cyrusimap.org/sasl', None)}
-
 mathjax_path = 'https://cdn.mathjax.org/mathjax/latest/MathJax.js'
 
 todo_include_todos = False
