$NetBSD: patch-.._columnize-0.3.4.gemspec,v 1.2 2011/08/12 16:56:10 taca Exp $

Remove unsupported rdoc option.

--- ../columnize-0.3.4.gemspec.orig	2011-08-08 00:30:06.000000000 +0000
+++ ../columnize-0.3.4.gemspec
@@ -70,7 +70,6 @@ licenses: 
 - GPL2
 post_install_message: 
 rdoc_options: 
-- --verbose
 - --main
 - README
 - --title
